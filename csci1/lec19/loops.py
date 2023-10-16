i = 1
while i <= 10:
    print(i)
    i = i + 1  # increment i

print("-------")

i = 10
while i >= 1:
    print(i)
    i = i - 1  # decrement i

print("-------")

sum = 0
i = 1
while i <= 10:
    # add the current value of i into sum
    sum = sum + i
    i = i + 1  # increment i

# sum now holds the correct sum of 1+2+3+...+10
print("the sum is:", sum)

print("-------")

L = [5, 6, 7, 8, 9, 1, 13]

i = 0  # 0 is always the first index of every list
while i <= len(L) - 1:  # len(L) - 1 is the last index of every list L
    # do stuff with L[i]
    print(L[i])
    # increment i
    i = i + 1












