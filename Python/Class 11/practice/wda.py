s=1
x=int(input('Enter the value of x : '))
for i in range(1,int(input('Enter the limit : '))):
    print(s,'+',i,'/',x**i)
    s+=i/x**i
print(s)
