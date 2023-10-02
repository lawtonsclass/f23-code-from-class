import turtle

turtle.shape('turtle')

print(turtle.pos())

# draw the L
turtle.up()
turtle.goto(-150, 100)
turtle.down()
turtle.goto(-150, -100)
turtle.goto(-25, -100)

# move to the start of the N
turtle.up()
turtle.goto(25, -100)
turtle.down()

# draw the N
turtle.goto(25, 100)
turtle.goto(150, -100)
turtle.goto(150, 100)
