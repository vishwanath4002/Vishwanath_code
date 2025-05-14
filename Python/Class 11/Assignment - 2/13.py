n=int(input('Enter the number : '))
i=1
s=0
while i<n:
    if n%i==0:
        s+=i
    i+=1
if s==n:
    print('%s is a perfect number.'%n)
else:
    print('%s is not a perfect number.'%n)
