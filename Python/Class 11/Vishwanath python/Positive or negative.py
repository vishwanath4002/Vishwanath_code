#Check whether an entered number is psitive or negative.
def p():
    a=float(input("Enter a number : "))
    if a>0:
        print(a,"is positive.")
    elif a<0:
        print(a,"is negative.")
    else:
        print("Zero.")
    print("\nTo run the program, type [p()].")
p()
