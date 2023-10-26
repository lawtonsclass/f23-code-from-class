def sum1To(n):
    sum = 0

    i = 1
    while i <= n:
        sum = sum + i
        i = i + 1

    # give back the final sum
    return sum

print(sum1To(5) * 3)

def sumOdd1To(n):
    sum = 0

    i = 1
    while i <= n:
        sum = sum + i
        i = i + 2

    # give back the final sum
    return sum

print(sumOdd1To(7) * 2)
# sumOdd1To(8) --> 1 + 3 + 5 + 7
print(sumOdd1To(8) * 2)












