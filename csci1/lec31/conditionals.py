# ask the user for their height
height = int(input("Enter your height in inches: "))
if height < 48:
    print("Sorry, you can't go on this ride :(")
else:
    print('You can go on the ride! :)')

grade = float(input("Enter your grade as a percentage: "))
if grade >= 90.0:
    print("A")
elif grade >= 80.0:
    print("B")
elif grade >= 70.0:
    print("C")
elif grade >= 60.0:
    print("D")
else:
    print("F")
