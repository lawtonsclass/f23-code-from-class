import turtle
import random

turtle.speed("fastest")
turtle.shape("turtle")

turtle.pensize(8) # thick lines

def drawRectangle(upper_left, width, height, color):
  turtle.up()
  turtle.fillcolor(color)
  turtle.pencolor('black')
  turtle.goto(upper_left)
  turtle.down()
  turtle.begin_fill()
  turtle.setheading(0) # face east
  turtle.forward(width)
  turtle.right(90)
  turtle.forward(height)
  turtle.right(90)
  turtle.forward(width)
  turtle.right(90)
  turtle.forward(height)
  turtle.end_fill()

def drawLine(start, end, color='black'):
  turtle.up()
  turtle.pencolor(color)
  turtle.goto(start)
  turtle.down()
  turtle.goto(end)

def pickRandomColor():
  # make white appear 6× more often
  colors = ['red', 'yellow', 'blue', 'black'] + (['white'] * 6)
  return random.choice(colors)

# our drawing space will be from (-270, -360) to (270, 360)
minx, miny = -270, -360
maxx, maxy = 270, 360

# pick 6 random vertical line x coordinate locations in addition to the edges
vertical_lines = [minx, maxx]
for i in range(6):
  vertical_lines = vertical_lines + [random.randint(minx+20, maxx-20)]

# 8 horizontal line y coordinate locations
horizontal_lines = [miny, maxy]
for i in range(8):
  horizontal_lines = horizontal_lines + [random.randint(miny+20, maxy-20)]

# draw the horizontal and vertical lines
for x_coord in vertical_lines:
  drawLine((x_coord, miny), (x_coord, maxy))
for y_coord in horizontal_lines:
  drawLine((minx, y_coord), (maxx, y_coord))

while input('type q to quit, anything else to continue: ') != 'q':
  ybounds = random.sample(horizontal_lines, 2)
  ybounds.sort() # ybounds[0] < ybounds[1]
  # technically, ybounds[0] might = ybounds[1], but it's unlikely
  xbounds = random.sample(vertical_lines, 2)
  xbounds.sort()
  width = xbounds[1] - xbounds[0]
  height = ybounds[1] - ybounds[0]
  upper_left = (xbounds[0], ybounds[1]) # smaller xbound, bigger ybound
  drawRectangle(upper_left, width, height, pickRandomColor())

# draw white lines around the edges
drawLine((minx, maxy), (maxx, maxy), 'white')
drawLine((maxx, maxy), (maxx, miny), 'white')
drawLine((maxx, miny), (minx, miny), 'white')
drawLine((minx, miny), (minx, maxy), 'white')

turtle.hideturtle()
turtle.done()
