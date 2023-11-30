import random

total_darts = 10000000
darts_inside_circle = 0

for i in range(total_darts):
    # throw a dart
    x = random.uniform(-1.0, 1.0)
    y = random.uniform(-1.0, 1.0)
    # see if it landed in the circle
    if x*x + y*y <= 1.0:
        darts_inside_circle = darts_inside_circle + 1

print(darts_inside_circle / total_darts * 4)
    
