#Write a program to print the multiplication table of a numer entered by the user

n=int(input("Multiplication table.\nEnter the number : "))
for i in range(1,11):
    print(n,"*",i,"=",i*n)
