#14
from math import factorial
s=0

l=eval(input('\nEnter the list : '))
while True:
    print('\n1.Display the factorail of all the elements in the list.\n2.Display the sum of all odd numbers in the list.\n3.Exit.')
    c=int(input('Enter your choice (1/2/3) : '))

    for i in l:
        if i%2!=0:
            s+=i
        else:
            continue
    
    if c==1:

        print('Factorial of elements :')
        for i in l:
            print('%s : %s'%(i,factorial(i)))

    elif c==2:

        print('Sum of all the odd numbers in the list is :',s)

    elif c==3:

        break
    
    else:

        print('Invalid entry.')
    
