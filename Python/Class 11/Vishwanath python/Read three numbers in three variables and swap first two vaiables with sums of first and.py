'''Read three numbers in three variables and swap first two vaiables with sums of first and
second ,second and third numbers respectively'''
a,b,c=map(float,input("Enter the three numbers : ").split())
a,b=a+b,b+c
print("Sum of first two numbers :",a,"\nSum of second and third numbers :",b)
