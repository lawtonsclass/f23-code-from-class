// THIS IS THE WORLD'S UGLIEST IMPLEMENTATION AND I AM SORRY
// to compile: g++ fade.cpp libraylib.a -o fade
// to run: ./fade cat.png

#include "raylib.h"
#include <atomic>
#include <chrono>
#include <queue>
#include <thread>
#include <iostream>
using namespace std;

void pause(double seconds) {
  std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}

// in case the user clicks the X early to close the window
std::atomic<bool> shouldContinue(true);

struct Pixel {
  int r, g, b;  // color of pixel
  int x, y;     // coordinates of pixel
};

// returns true if pixel b is brighter than pixel a
// (it's backwards because priority_queue uses < like sane people use >)
bool operator<(const Pixel& a, const Pixel& b) {
  int lightnessA = (a.r + a.g + a.b) / 3;
  int lightnessB = (b.r + b.g + b.b) / 3;

  // if they're the same lightness just arbitrarily order based on x & y
  return lightnessB > lightnessA || (lightnessA == lightnessB && a.x < b.x) ||
         (lightnessA == lightnessB && a.x == b.x && a.y < b.y);
}

Image currentImage;

// this is the function that actually does the interesting stuff
void fade() {
  // get every pixel and order by lightness

  priority_queue<Pixel> pq;  // priority_queue of Pixels

  // add every pixel in the image to the priority_queue
  for (int x = 0; x < currentImage.width; x++) {
    for (int y = 0; y < currentImage.height; y++) {
      Color c = GetImageColor(currentImage, x, y);
      pq.push({c.r, c.g, c.b, x, y});
    }
  }

  // keep popping off the brightest pixels
  unsigned int i = 0;
  while (!pq.empty()) {
    // take the next brightest pixel and change it to white
    Pixel p = pq.top();
    Color white = {255, 255, 255, 255};
    ImageDrawPixel(&currentImage, p.x, p.y, white);

    pq.pop();
    i++;
    
    // the screen is constantly updating--we need to slow things down
    // to see the effect
    // pause after we change 1000 pixels
    if (i % 1000 == 0 || pq.empty()) {
      pause(0.02);
      if (!shouldContinue) return;
    }
  }
}

int main(int argc, char* argv[]) {
  SetTraceLogLevel(LOG_WARNING);

  currentImage = LoadImage(argv[1]);

  InitWindow(currentImage.width, currentImage.height, "fade");
  SetTargetFPS(60);

  thread t(fade);

  // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
      // Update
      //----------------------------------------------------------------------------------
      Texture2D imageTexture = LoadTextureFromImage(currentImage);
      //----------------------------------------------------------------------------------

      // Draw
      //----------------------------------------------------------------------------------
      BeginDrawing();

          ClearBackground(RAYWHITE);

          DrawTexture(imageTexture, 0, 0, WHITE);

      EndDrawing();
      //----------------------------------------------------------------------------------

      UnloadTexture(imageTexture);
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();        // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  shouldContinue = false;
  t.join();

  return 0;
}
