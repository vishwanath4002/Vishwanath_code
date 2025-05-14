#WAP to print the factorial of a number entered by user
n=int(input('Enter the number : '))
s=1
for i in range(1,n+1):
    s*=i
print('%s! = %s'%(n,s))
