
a=float(input("Enter the first number : "))
b=float(input("Enter the second number : "))
o=str(input("Enter the arithmetic operator [+,-,*,/,//,%,**] : "))
if o=="+":
    print(a,"+",b,"=",a+b)
elif o=="-":
    print(a,"-",b,"=",a-b)
elif o=="*":
     print(a,"*",b,"=",a*b)
elif o=="/":
    if b==0:
         print("Division by zero is not possible.")
    else:
         print(a,"/",b,"=",a/b)
elif o=="//":
     if b==0:
         print("Division by zero is not possible.")
     else:
         print(a,"//",b,"=",a//b)
elif o=="%":
     print(a,"%",b,"=",a%b)
elif o=="**":
     print(a,"**",b,"=",a**b)
else:
    print("invalid choice")
