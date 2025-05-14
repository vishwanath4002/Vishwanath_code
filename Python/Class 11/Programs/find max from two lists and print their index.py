#find max from two lists and print their index
s=[]
x=[]
n=int(input('Enter the limit of the first list : '))
for i in range(n):
    s.append(int(input('Enter the number : ')))
print(s)
n=int(input('\nEnter the limit of the second list : '))
for i in range(n):
    x.append(int(input('Enter the number : ')))
print(x)
maximum=max(max(s),max(x))
if max(x)==max(s):
    print('\nThe maximum element is',maximum,' and it belongs to both lists.\nIts index in the first list is :',s.index(max(s)),'\nIts index in the second list is :',x.index(max(x)))
elif maximum not in x:
    print('\nThe maximum element is',maximum,' and it belongs to the first list.\nIts index is',s.index(max(s)))
else:
    print('\nThe maximum element is',maximum,' and it belongs to the second list.\nIts index is',x.index(max(x)))
