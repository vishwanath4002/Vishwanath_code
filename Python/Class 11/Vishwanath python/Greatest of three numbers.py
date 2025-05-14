#Find greatest among three numbers entered by the user
a=float(input("Enter the first number : "))
b=float(input("Enter the second number : "))
c=float(input("Enter the third number : "))
if a>b and a>c:
    print(a,"is the greatest.")
if b>a and b>c:
    print(b,"is the greatest.")
else:
    print(c,"is the greatest.")
