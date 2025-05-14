#6
def fact(n):
    f=n
    for i in range(1,n):
        f*=i
    return f
while True:
    s=0
    ch=int(input('1.Sum of n numbers\n2.Factorial of a number\n3.Exit\nEnter your choice (1, 2 or 3): '))
    if ch==1:
        for i in range(int(input('Enter the number of numbers : '))):
            s+=float(input('Enter the number : '))
        print('The sum is',s)
    elif ch==2:
        n=int(input('Enter the number : '))
        print('Factorial of %s is %s.'%(n,fact(n)))
    elif ch==3:
        break
    else:
        print('Invalid entry.')
