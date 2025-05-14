#1-x+x^2-x^3...
x=int(input('Enter the number : '))
n=int(input('Enter the number of terms : '))
s=0
sign=1
for i in range(n):
    s+=(x**i)*sign
    sign*=-1
print(s)
