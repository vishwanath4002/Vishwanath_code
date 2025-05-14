#WAP to print n natural numbers and display their sum [while loop]
n=int(input('Enter the number of natural numbers : '))
i=1
s=0
while i<=n:
    print(i)
    s+=i
    i+=1
print('The sum of first %s natural numbers is %s.'%(n,s))
    
