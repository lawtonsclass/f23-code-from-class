# computes n!
def fact(n):
    if n == 1:
        # base case
        return 1
    else:
        # recursive case
        x = fact(n-1)
        return n * x

print(fact(5))

print(fact(3))
