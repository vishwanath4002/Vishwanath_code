#Count frequency of an element in a list
n=int(input('Enter the limit : '))
a=[]
for i in range(n):
    a.append(int(input('Enter the element : ')))
x=int(input('Enter the element to cout frequency'))
c=0
for i in a:
    if x==i:
        c+=1
print('%s appears %s times.'%(x,c))
        
