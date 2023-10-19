// THIS IS THE WORLD'S UGLIEST IMPLEMENTATION AND I AM SORRY
// to get this working:
// install the qt library: sudo apt install -y qtcreator qtbase5-dev qt5-qmake cmake
// generate the Makefile: qmake -o Makefile fade.pro
// make
// ./fade cat.png
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QPixmap>
#include <atomic>
#include <chrono>
#include <queue>
#include <thread>

#include "helper.h"
using namespace std;

void pause(double seconds) {
  std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}

QGraphicsPixmapItem* p;
QImage currentImage;
Helper h;
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

// this is the function that actually does the interesting stuff
void fade() {
  // get every pixel and order by lightness

  priority_queue<Pixel> pq;  // priority_queue of Pixels

  // add every pixel in the image to the priority_queue
  for (int x = 0; x < currentImage.width(); x++) {
    for (int y = 0; y < currentImage.height(); y++) {
      int r, g, b;
      QColor pixel = currentImage.pixelColor(x, y);
      pixel.getRgb(&r, &g, &b);
      pq.push({r, g, b, x, y});
    }
  }

  // keep popping off the brightest pixels
  unsigned int i = 0;
  while (!pq.empty()) {
    // take the next brightest pixel and change it to white
    Pixel p = pq.top();
    currentImage.setPixelColor(p.x, p.y, QColor::fromRgb(255, 255, 255));
    pq.pop();
    i++;
    // update the screen after we change 1000 pixels
    if (i % 1000 == 0 || pq.empty()) {
      pause(0.02);
      emit h.valueChanged(currentImage);
      if (!shouldContinue) return;
    }
  }
}

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QGraphicsScene scene;
  QGraphicsView view(&scene);
  p = scene.addPixmap(QPixmap(argv[1]));
  currentImage = p->pixmap().toImage();

  QObject::connect(&h, &Helper::valueChanged, &h, &Helper::setValue);

  thread t(fade);

  view.show();
  int res = a.exec();
  shouldContinue = false;
  t.join();
  return res;
}
