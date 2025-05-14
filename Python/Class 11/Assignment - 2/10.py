#WAP to input a number and test if its a prime number
n=int(input('Enter the number : '))
for i in range(2,n):
    if n%i==0:
        print('%s is not a prime number.'%n)
        break
else:
    print('%s is a prime number.')
