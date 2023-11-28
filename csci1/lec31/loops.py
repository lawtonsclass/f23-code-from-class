i = 1
while i <= 10:
    print(i)
    i = i + 1

    if i == 8:
        # stop early with 'break'
        break

# keep track of the sum in a variable
total = 0
nextNum = int(input("Enter the next number or -1: "))
while nextNum != -1:
    # add nextNum into total
    total = total + nextNum
    # get the next number
    nextNum = int(input("Enter the next number or -1: "))

# when we get here, nextNum must be -1
# output the sum
print('sum:', total)
