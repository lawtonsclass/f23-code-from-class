def sumList(L):
    if len(L) == 0:
        return 0
    elif len(L) == 1:
        return L[0]
    else:
        # recursive case
        # step 1: divide
        # chop L into two halves
        size = len(L)
        first_half = L[0:(size // 2)]
        second_half = L[(size // 2):size]
        # step 2: conquer
        # recursively call sumList on the two halves
        first_half_sum = sumList(first_half)
        second_half_sum = sumList(second_half)
        # the final answer is the sum of the two smaller answers!
        return first_half_sum + second_half_sum

print(sumList([8, 6, 7, 5, 3, 0, 9, 2]))
print(sumList([8, 6, 7, 5, 3, 0, 9]))
print(sumList([]))
