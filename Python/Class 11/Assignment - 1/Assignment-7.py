#7-WAP to find the largest among the three different input numbers.
a,b,c=map(float,input("Enter the three numbers : ").split())
if a>b and a>c:
    print(a,"is the greatest.")
elif b>a and b>c:
    print(b,"is the greatest.")
else:
    print(c,"is the greatest.")
