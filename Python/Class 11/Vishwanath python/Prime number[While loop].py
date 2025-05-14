#Check if a number is a prime number
n=int(input('Enter the number : '))
i=2
while i<n:
    if n%i==0:
        print('%s is not a prime number.'%n)
    i+=1
    break
else:
    print('%s is a prime number.'%n)
