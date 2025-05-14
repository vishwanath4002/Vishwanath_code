#write a program to print sum of n natural numbers(while loop)
n=int(input('Enter the number of natural numbers : '))
s=0
for i in range(1,n+1):
    s+=i
print('The sum is %s.'%s)
