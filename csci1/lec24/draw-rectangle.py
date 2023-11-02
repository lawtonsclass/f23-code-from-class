import turtle

turtle.shape("turtle")

def drawRectangle(ul, w, h, color):
    turtle.pencolor(color)
    
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


drawRectangle((50, 100), 200, 300, "black")
drawRectangle((-50, -100), 50, 30, "red")
drawRectangle((0, 0), 75, 75, "blue")








