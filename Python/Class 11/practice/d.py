def prime(n):
    for i in range(2,n):
        if n%i==0:
            return False
    else:
        return True

s=0
ch='yes'
while ch=='yes':
    n=int(input('Enter the number : '))
    if n<0:
        break
    else:
        if prime(n):
            s+=n
    ch=input('Do you want to continue (yes/no) : ')
    
if s==0:
    print('There are no prime numbers.')
else:
    print('Sum of prime numbers :',s)
