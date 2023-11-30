import turtle

turtle.shape("turtle")

def drawSquare(center, width, color):
    center_x = center[0]
    center_y = center[1]
    ul = (center_x - width/2, center_y + width/2)

    turtle.up()
    turtle.goto(ul)
    turtle.down()
    turtle.setheading(0)

    turtle.fillcolor(color)

    turtle.begin_fill()
    turtle.forward(width)
    turtle.right(90)
    turtle.forward(width)
    turtle.right(90)
    turtle.forward(width)
    turtle.right(90)
    turtle.forward(width)
    turtle.end_fill()

drawSquare((0, 0), 200, "red")
drawSquare((0, 0), 125, "white")
drawSquare((0, 0), 50, "red")
