import turtle

turtle.shape("turtle")

def drawN(ul, w, h):
    x = ul[0]
    y = ul[1]

    # draw a w by h N character

    # start at (x, y-h)
    turtle.up()
    turtle.goto(x, y-h)
    turtle.down()

    turtle.goto(x, y)
    turtle.goto(x+w, y-h)
    turtle.goto(x+w, y)


drawN((50, 100), 200, 300)
drawN((-50, -100), 50, 30)
drawN((0, 0), 75, 75)








