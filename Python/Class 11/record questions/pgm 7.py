#7
n=int(input('Enter the number : '))
st=str()
s=0
for i in range(1,n):
    if n%i==0:
        st+=str(i)+'\t'
        s+=i
print('The divisors are :',st)
if s==n:
    print('%s is a perfect number.'%(n))
else:
    print('%s is not a perfect number.'%(n))
