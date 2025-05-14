def factorial(n):
    if n<0:
        return 'Invalid entry.'
    else:
        if n==0:
            return 1
        return n*factorial(n-1)

def fib(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    return fib(n-1)+fib(n-2)

while True:
    print()
    c=int(input('1.Factorial.\n2.Fibonacci series upto n terms.\n3.Exit\nEnter your choice (1,2,3) : '))
    print()
    if c==1:
        n=int(input('Enter the number : '))
        print(factorial(n))
    elif c==2:
        n=int(input('Enter the number of terms : '))
        for i in range(n):
            print(fib(i),end=', ')
    elif c==3:
        break
    else:
        print('Invalid entry.')

            
