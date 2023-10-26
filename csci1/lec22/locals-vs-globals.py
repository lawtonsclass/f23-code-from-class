# this is a *global* variable--it is visible to everybody
x = 42

print(x)

def blah():
    global x # I want to modify the global var x
    x = x + 1
    
    print(x * 2) # x exists in here--it exists everywhere!

    y = 3  # this is a *local* variable
    print(y * 2)

blah()

print(y)
