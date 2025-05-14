def isPrime(n):
    for i in range(2,n):
        if n%i==0:
            return False
    else:
        return True

def isPalindrome(n):
    x=0
    t=n
    while n>0:
        x=x*10+n%10
        n//=10
    if x==t:
        return True
    else:
        return False
    
while True:
    
    c=int(input('\n1.Prime\n2.Palindrome\n3.Exit\nEnter your choice (1,2,3): '))
    print()
    if c==1: 
        a=int(input('Enter the number : '))
        if isPrime(a):
            print('%s is prime.'%a)
        else:
            print('%s is not prime.'%a)
    elif c==2:
        a=int(input('Enter the number : '))
        if isPalindrome(a):
            print('%s is a palindrome.'%a)
        else:
            print('%s is not a palindrome.'%a)
    elif c==3:
        break
    else:
        print('Invalid entry. Please try again.')

