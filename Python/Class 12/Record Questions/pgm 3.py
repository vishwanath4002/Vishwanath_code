def perfect(n):
    s=1
    for i in range(2,n):
        if n%i==0:
            s+=i
        else:
            continue
    if s==n:
        return True
    else:
        return False

def armstrong(n):
    x=str(n)
    s=0
    for i in x:
        s+=(int(i))**len(x)
    if s==n:
        return True
    else:
        return False
while True:
    c=int(input('\n1.Perfect number.\n2.Armstrong number.\n3.Exit.\nEnter your choice (1,2,3): '))
    print()
    if c==1:
        n=int(input('Enter the number :'))
        if perfect(n):
            print('%s is a perfect number.'%n)
        else:
            print('%s is not a perfect number.'%n)
    elif c==2:
        n=int(input('Enter the number :'))
        if armstrong(n):
            print('%s is an Armstrong number.'%n)
        else:
            print('%s is an not an Armstrong number.'%n)
    elif c==3:
        break
    else:
        print('Invalid entry. Please try again.')
