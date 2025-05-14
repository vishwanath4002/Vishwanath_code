#x+x**2/2! - x**3/3! + .... n terms
x=eval(input('Enter the value of x : '))
n=int(input('Enter the number of terms : '))
s=x
sign=1
for i in range(2,n+1):
    f=1
    for j in range(1,i+1):
        f*=j
    s+=(x**i/f)*sign
    sign*=-1
print('sum is : ',s)
