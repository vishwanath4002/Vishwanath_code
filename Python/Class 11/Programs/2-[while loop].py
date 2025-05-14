#write a program to print sum of n natural numbers(while loop)
n=int(input('Enter the number of natural numbers : '))
s=0
i=1
while i<=n:
    s+=i
    i+=1
print("The sum is %s"%s)
