import turtle
import random
import math

turtle.shape("turtle")

def drawRectangle(ul, w, h): 
    # move to ul
    turtle.up()
    turtle.goto(ul[0], ul[1])
    turtle.down()
    # face right
    turtle.setheading(0)
    # go forward by width
    turtle.forward(w)
    # turn right 90
    turtle.right(90)
    # go forward by height
    turtle.forward(h)
    # ...
    turtle.right(90)
    turtle.forward(w)
    turtle.right(90)
    turtle.forward(h)

# draw the bounding square (i.e., the walls)
drawRectangle((-200, 200), 400, 400)

# make the turtle the square!
turtle.shape('square')
turtle.fillcolor("purple")
turtle.turtlesize(2, 2)
turtle_width = 40

# we'll use these variables to keep track of where the square
# should be/where it should move
turtle_x = random.randint(-150, 150)
turtle_y = random.randint(-150, 150)
# these two variables together will form our direction
turtle_xoffset = random.uniform(-1.0, 1.0)
turtle_yoffset = random.uniform(-1.0, 1.0)
# let's *normalize* our direction so that it has a length 1 hypotenuse
direction_hyp_length = math.sqrt(turtle_xoffset**2 + turtle_yoffset**2)
turtle_xoffset = turtle_xoffset / direction_hyp_length
turtle_yoffset = turtle_yoffset / direction_hyp_length
# now the length of the hypotenuse is 1


# put the turtle in the correct starting location
turtle.up()
turtle.goto(turtle_x, turtle_y)

def bounce_if_hit_wall():
    global turtle_x
    global turtle_y
    global turtle_xoffset
    global turtle_yoffset
    
    if turtle_y <= -180:
        # we either hit the bottom wall, or we're trying to go below it
        # move the turtle back inside
        turtle_y = -180
        # change the y offset so we move upwards now
        turtle_yoffset = turtle_yoffset * -1

    if turtle_y >= 180:
        # we either hit the top wall, or we're trying to go above it
        # move the turtle back inside
        turtle_y = 180
        # change the turtle y offset so we move downwards now
        turtle_yoffset = turtle_yoffset * -1

    if turtle_x <= -180:
        # we either hit the left wall, or we're trying to go past it
        # move the turtle back inside
        turtle_x = -180
        # change the turtle x offset so we move to the right now
        turtle_xoffset = turtle_xoffset * -1

    if turtle_x >= 180:
        # we either hit the right wall, or we're trying to go past it
        # move the turtle back inside
        turtle_x = 180
        # change the turtle x offset so we move to the left now
        turtle_xoffset = turtle_xoffset * -1

def drawFrame():
    global turtle_x
    global turtle_y
    global turtle_xoffset
    global turtle_yoffset
    
    # change the turtle's x coordinate by the offset
    turtle_x = turtle_x + turtle_xoffset
    # change the turtle's y coordinate by the offset
    turtle_y = turtle_y + turtle_yoffset

    # if we hit a wall, bounce off
    bounce_if_hit_wall()
    
    # redraw the turtle
    turtle.goto(turtle_x, turtle_y)

while True:
    # repeatedly, draw a new frame
    drawFrame()













