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

# make the turtle the paddle!
turtle.shape('square')
turtle.fillcolor("purple")
turtle.turtlesize(1.5, 6)

paddle_x = -170
paddle_y = 0
turtle.up()
turtle.goto(paddle_x, paddle_y)

def go_up():
    global paddle_y
    paddle_y = paddle_y + 10
    # make sure we don't go past the top
    if paddle_y >= 140:
        paddle_y = 140
    turtle.goto(paddle_x, paddle_y)

def go_down():
    global paddle_y
    paddle_y = paddle_y - 10
    # make sure we don't go past the bottom
    if paddle_y <= -140:
        paddle_y = -140
    turtle.goto(paddle_x, paddle_y)

# set up functions to run every time the up/down keys are pressed
turtle.onkeypress(go_up, "Up")
turtle.onkeypress(go_down, "Down")
turtle.listen()









