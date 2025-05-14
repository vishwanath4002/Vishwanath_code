#WAP to print Fibonacci series, first n elements
n=int(input('Enter the limit : '))
a=0
b=1
for i in range(n):
    print(a)
    c=a+b
    a,b=b,c

