# there are no types that need to be declared in python
# it just figures them out
x = 42
print(x)

print(type(x))
x = "asdf"
print(x)
print(type(x))

def add1(y): 
    # everything that's indented is the body of the function
    return y + 1

print(add1(42))

# the following is a list
# strings can use "s or 's
L = [1, 2, 'hi']
print(L[2])
C
grade = 77
if grade >= 90:
    print('A')
elif grade >= 70:
    print('C')
else:
    print('F')
