# this prints to the screen
print("Hello, world!")

# there's no difference between "s and 's
print('Hello, world!')

"""
Python has a REPL (read, eval, print loop)
"""

# x can have *any* type
x = 42
print(x)
x = 'hi mom'
print(x)

# def defines a function
def printXPlus1(x):
    print(x + 1)

printXPlus1(42)

l = [1, 2, 3]
for x in l:
    print(x*42)
