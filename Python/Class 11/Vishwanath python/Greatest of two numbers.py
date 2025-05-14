#Find greatest among two numbers entered by the user
a,b=map(float,input("Enter the numbers : ").split())
if a>b:
    print(a,"is greater than",b)
elif a<b:
    print(b,"is greater than",a)
else:
    print(a,"is equal to",b)
