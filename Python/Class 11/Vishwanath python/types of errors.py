#Compare two numbers
a,b=map(int,input("Enter two numbers : ").split())
if a>b and a<b:
    print(a,"is greater, and their difference is ",a-b)
else:
    print(b,"is greater, and their difference is ",b-a)    
