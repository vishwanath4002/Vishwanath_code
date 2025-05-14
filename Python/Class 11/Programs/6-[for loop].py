#Check if a number is perfect number[for loop]
s=0
n=int(input('Enter the number : '))
for i in range(1,n):
    if n%i==0:
        s+=i
if s==n:
    print('%s is a perfect number.'%n)
else:
    print('%s is not a perfect number.'%n)
