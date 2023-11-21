import turtle

# the fractal is recursive, but this program is not!

turtle.shape('turtle')
turtle.speed('fastest')
turtle.tracer(5000) # make the turtle really really fast
turtle.color('blue')
turtle.up()

# scale:1 zoom level
scale = 200

def isPointInTheMandelbrotSet(x, y):
  # turn (x, y) into x + iy (a complex number)
  num = complex(x, y)
  z = 0
  # try doing z = z**2 + num 100 times
  for i in range(100):
    z = z*z + num
  # see if after doing all that, z is still small
  # if it is, it's in the set
  # (abs on complex numbers returns their magnitude)
  if abs(z) < 100:
    return True
  else:
    return False

# fill in every possible (x, y) coordinate between (-300, -300) and (300, 300)
for x in range(-300, 301):
  for y in range(-300, 301):
    # this zooms in the graph
    xcoord = x / scale
    ycoord = y / scale

    # our current scaled coordinate is (xcoord, ycoord)
    # let's see if it's in the mandelbrot set
    if isPointInTheMandelbrotSet(xcoord, ycoord):
      # color it in if so!
      turtle.goto(x, y)
      turtle.down()
      turtle.forward(1) # fill in the pixel
      turtle.up()

turtle.update() # refreshes the screen
turtle.done()
