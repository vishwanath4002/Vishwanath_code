#Write a program to print duplicates to the end of the list
a=[]
new=[]
c=[]
n=int(input('Enter the limit : '))
for i in range(n):
    a.append(int(input('Enter the element : ')))
print(a)
for i in range(n):
    if a[i] not in new:
        new.append(a[i])
    else:
        c.append(a[i])
new.extend(c)
print('The list with the copies at the end is',new)




