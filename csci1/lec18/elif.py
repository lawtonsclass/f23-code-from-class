grade = float(input("Enter your grade: "))

if grade >= 90.0:
    print("A")
else:
    # could be C or F
    if grade >= 70:
        print("C")
    else:
        print("F")

### alternatively, using if-elif-else

if grade >= 90.0:
    print("A")
elif grade >= 70:
    print("C")
else:
    print("F")




