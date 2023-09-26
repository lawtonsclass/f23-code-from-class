import turtle
import math

print(turtle.position())

# make the turtle actually look like a turtle
turtle.shape('turtle')

# make the turtle go fast
# turtle.speed('fast')

# get the turtle into position
turtle.up()
turtle.setheading(180)
turtle.forward(200)
turtle.right(90)
turtle.forward(100)

turtle.down() # now we're ready to draw

# draw L
turtle.setheading(270)
turtle.forward(200)
turtle.left(90)
turtle.forward(125)

# space in between letters
turtle.up()
turtle.forward(40)
turtle.down()

# draw the N
turtle.left(90)
turtle.forward(200)

angle = math.degrees(math.atan(125/200))
turtle.right(180 - angle)

l = math.sqrt(125**2 + 200**2)
turtle.forward(l)

turtle.left(180 - angle)
turtle.forward(200)

# turtle.goto(0, 0)




