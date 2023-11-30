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

def drawCircle(center, width, color):
    center_x = center[0]
    center_y = center[1]
    starting_point = (center_x, center_y - width/2)

    turtle.up()
    turtle.goto(starting_point)
    turtle.down()
    turtle.setheading(0)

    turtle.fillcolor(color)

    turtle.begin_fill()
    turtle.circle(width / 2)
    turtle.end_fill()

def drawTriangle(center, width, color):
    center_x = center[0]
    center_y = center[1]
    bl = (center_x - width/2, center_y - width/3)

    turtle.up()
    turtle.goto(bl)
    turtle.down()
    turtle.setheading(0)

    turtle.fillcolor(color)

    turtle.begin_fill()
    turtle.forward(width)
    turtle.left(180 - 60)
    turtle.forward(width)
    turtle.left(180 - 60)
    turtle.forward(width)
    turtle.end_fill()

# drawSquare((0, 0), 200, "red")
# drawSquare((0, 0), 125, "white")
# drawSquare((0, 0), 50, "red")

# drawCircle((0, 0), 200, "red")
# drawCircle((0, 0), 125, "white")
# drawCircle((0, 0), 50, "red")

# drawTriangle((0, 0), 200, "red")
# drawTriangle((0, 0), 125, "white")
# drawTriangle((0, 0), 50, "red")

def drawTargetLogo(center, drawShape):
    drawShape(center, 200, "red")
    drawShape(center, 125, "white")
    drawShape(center, 50, "red")

drawTargetLogo((150, 150), drawSquare)
drawTargetLogo((-150, -150), drawCircle)
drawTargetLogo((0, 0), drawTriangle)









