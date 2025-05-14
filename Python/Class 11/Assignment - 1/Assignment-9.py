#9-WAP to perform area and perimeter of a square according to user’s choice (menu driven)
c=str(input("Enter 1 for getting the area of the square.\nEnter 2 for getting the perimeter of the square.\nEnter your choice : "))
if c=="1":
    s=float(input("Enter the side of the square : "))
    print("The area of the square is :",s**2)                    #a=s**2
elif c=="2":
    s=float(input("Enter the side of the square : "))
    print("The perimeter of the square is :",s*4)                    #p=s*4
else:
    print("invalid choice")
