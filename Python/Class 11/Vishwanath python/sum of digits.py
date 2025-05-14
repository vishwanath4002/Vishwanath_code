a=int(input('Enter the number : '))
s=0
while a>0:
    d=a%10
    s+=d
    a//=10
print(s)
