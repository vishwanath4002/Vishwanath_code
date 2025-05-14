#WAP to calculate and print the sum of even and odd integers of the first n natural numbers
n=int(input('Enter the number of natural numbers : '))
se=0
so=0
for i in range(1,n+1):
    if i%2==0:
        se+=i
    else:
        so+=i
print('Sum of even numbers : %s\nSum of odd numbers : %s'%(se,so))
        
