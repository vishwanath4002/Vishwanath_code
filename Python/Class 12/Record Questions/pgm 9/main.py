from Series import *
while True:
    print()
    c=int(input('\n1.First n Natural numbers.\n2.n Terms of Fibonacci series.\n3.Squares of first n natural numbers.\n4.Prime numbers upto n\n5.Exit\nEnter your choice (1,2,3,4,5) : '))
    print()
    if c==1:
        naturalNumbers(int(input('Enter the value of n : ')))
    elif c==2:
        fibonacciSeries(int(input('Enter the value of n : ')))
    elif c==3:
        square(int(input('Enter the value of n : ')))
    elif c==4:
        primeNumbers(int(input('Enter the value of n : ')))
    elif c==5:
        break
    else:
        print('Invalid entry. Please try again.')
