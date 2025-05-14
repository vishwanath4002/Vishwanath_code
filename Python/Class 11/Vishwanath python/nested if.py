#Greatest of three numbers
a,b,c=map(float,input("Enter three numbers : ").split())
if a>b:
    if a>c:
        print(a,"is the greatest.")
    else:
        print(c,"is the greatest.")
elif b>c:
    print(b,"is the greatest.")
else:
    print(c,"is the greatest")
