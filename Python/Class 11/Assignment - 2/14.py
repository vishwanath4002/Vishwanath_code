#WAP to input a number a test if it is a prefect number
n=int(input('Enter the number : ')) 
s=0
while n>0:
    d=n%10
    s=s+d
    n=n//10
print(s)
