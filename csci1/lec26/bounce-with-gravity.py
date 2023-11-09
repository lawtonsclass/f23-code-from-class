import turtle
import random
import time

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

# make the turtle the ball!
turtle.shape('circle')
turtle.fillcolor("pink")
turtle.turtlesize(2, 2)
turtle_width = 40

# we'll use these variables to keep track of where the ball
# should be/where it should move
turtle_x = random.randint(-100, 100)
turtle_y = 200 - turtle_width/2

# the intial velocity of the ball is 0
turtle_velocity = 0
# the units for this acceleration variable are units/frame^2
turtle_acceleration = -0.5

# put the turtle in the correct starting location
turtle.up()
turtle.goto(turtle_x, turtle_y)

def drawFrame():
    global turtle_y
    global turtle_velocity

    # the acceleration affects the velocity
    turtle_velocity = turtle_velocity + turtle_acceleration
    # change the turtle's y coordinate by the offset
    turtle_y = turtle_y + turtle_velocity

    # if we hit a wall, bounce off
    if turtle_y <= -200 + turtle_width/2:
        # we either hit the bottom wall, or we're trying to go below it
        # move the turtle back inside
        turtle_y = -200 + turtle_width/2
        # change the turtle offset so we move upwards now
        # turtle_velocity = turtle_velocity * -1
        # create a perfectly elastic collision by hard coding the new acceleration
        turtle_velocity = 19.0

    if turtle_y >= 200 - turtle_width/2:
        # we either hit the top wall, or we're trying to go above it
        # move the turtle back inside
        turtle_y = 200 - turtle_width/2
        # change the turtle offset so we move downwards now
        turtle_velocity = turtle_velocity * -1
    
    # redraw the turtle
    turtle.goto(turtle_x, turtle_y)
    # time.sleep(0.1)

while True:
    # repeatedly, draw a new frame
    drawFrame()













