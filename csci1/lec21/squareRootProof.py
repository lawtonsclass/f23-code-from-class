import math

n = 0
while n <= 101:
    if math.sqrt(n) > 10:
        print('False!')
        quit()
    n = n + 1

# if we ever get here, the statement must've been true
print('True!')
