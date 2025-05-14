#Read numbers and display the mean of the list
n=int(input('Enter the limit : '))
a=[]
for i in range(n):
    a.append(int(input('Enter the %sth number :'%(i+1))))
s=0
for i in a:
    s+=i
print('Mean =',s/n)
