import math
# now we're allowed to use all the math library functions!

# let's calculate the area of a circle with radius 4.5
# pi * r**2
radius = 4.5
area = math.pi * (radius**2)
print(area)

# let's calculate the sqrt of a num that the user types!
num = input('Enter a #: ')
num_as_float = float(num)
print(math.sqrt(num_as_float))

sin_of_num = math.sin(num_as_float)
print('The sin of', num_as_float, 'is', sin_of_num)
