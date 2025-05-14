#8
def fact(n):
    f=n
    for i in range(1,n):
        f*=i
    return f
s=0
x=float(input('Enter the value of x : '))
for i in range(int(input('Enter the limit : '))):
    n=2*(i+1)-1
    f=fact(n)
    s+=((-1)**i)*f/x**(i+1)
print('Sum :',s)
