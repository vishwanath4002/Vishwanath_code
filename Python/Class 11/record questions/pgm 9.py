#9
n=int(input('Enter the number : '))
s=0
for i in range(2,n):
    if n%i==0:
        print('It is not a prime number.')
        break
else:
    print('It is a prime number.')
for x in str(n):
    s+=int(x)**3
if s==n:
    print('It is an armstrong number.')
else:
    print('It is not an armstrong number.')
        
