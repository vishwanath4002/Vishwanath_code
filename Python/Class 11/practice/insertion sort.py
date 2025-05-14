l=eval(input('Enter the list : '))

#   [12,11,13,5,6]

for i in range(1,len(l)-1):
    a=l[i]
    for j in range(0,i):
        if a<l[j]:
            continue
        else:
            l.remove(a)
            l.insert(j,a)
            break
print(l)
