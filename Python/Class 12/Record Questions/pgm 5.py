def bubble_sort(l):
    for i in range(len(l)-1):
        is_swapped=False
        for j in range(len(l)-(i+1)):
            if l[j]>l[j+1]:
                l[j],l[j+1]=l[j+1],l[j]
                is_swapped=True
        if is_swapped==False:
            break
    return l
while True:
    print()
    l=[]
    n=int(input('Enter the number of terms: '))
    for i in range(n):
        l.append(int(input('Enter element %s : '%(i+1))))
    
    print(bubble_sort(l))
    c=input('Do you want to continue?: ')
    if c=='no':
        break
