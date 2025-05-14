#Compare two equal sized lists and print the index of where they first differ
x=[]
y=[]
n=int(input('Enter the limit of the lists : '))
print('first list')
for i in range(n):
    x.append(int(input('Enter the element : ')))
print(x)
print('second list')
for i in range(n):
    y.append(int(input('Enter the element : ')))
print(y)
for i in range(n):
    if x[i]==y[i]:
        continue
    else:
        break
print('They differ at index position',i)
