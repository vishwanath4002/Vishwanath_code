#Find the minimum element from a list and find index position of the element without min() and index()
n=int(input('Enter the limit : '))
a=[]
for i in range(n):
    a.append(int(input('Enter the %sth number : '%(i+1))))
print(a)
minimum=a[0]
index=0
for i in range(len(a)):
    if a[i]<minimum:
        minimum=a[i]
        index=i
print('The minimum element is %s and the index is %s'%(minimum,index))
    
