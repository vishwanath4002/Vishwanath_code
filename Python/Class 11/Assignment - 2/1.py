#WAP to print n natural numbers and display their sum[for loop]
n=int(input('Enter the number of natural numbers : '))
s=0
for i in range(1,n+1):
    print(i)
    s+=i
print('The sum of first %s natural numbers is %s.'%(n,s))
