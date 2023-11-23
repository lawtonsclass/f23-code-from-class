# return n**m
def pow(n, m):
    if m == 0:
        # anything to the 0th power is 1
        return 1
    else:
        # recursive case: n^m = n * n^(m-1)
        return n * pow(n, m-1)

print(pow(2, 4))
print(pow(2.5, 5))
