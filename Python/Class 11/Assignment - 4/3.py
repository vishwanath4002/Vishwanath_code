#Search for an element in a given list of numbers
s=[]
n=int(input('Enter the limit : '))
for i in range(n):
    s.append(int(input('Enter the number : ')))
print(s)
x=int(input('Enter the element to be found : '))
for i in range(n):
    if s[i]==x:
        print('Element found at position',i)
        break
else:
    print('Element not found.')
