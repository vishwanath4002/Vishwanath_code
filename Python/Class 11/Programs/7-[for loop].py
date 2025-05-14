#Check if the number is prime(for loop)
n=int(input('Enter the number : '))
for i in range(2,n):
    if n%i==0:
        print('%s is not a prime number.'%n)
        break
else:
    print('%s is a prime number.'%n)
