#5-Write a program to read three numbers in three variables and swap first two variables with the sum of first and second, second and third numbers respectively.
a,b,c=map(float,input("Enter three numbers : ").split())
a,b=a+b,b+c
print("Sum of the first two numbers is",a,".\nSum of the second and third number is",b,".")
