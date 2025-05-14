def bin_search(a,e):
    l=0
    h=len(a)
    while l<h:
        m=(l+h)//2
        if a[m]==e:
            return m
        elif a[m]<e:
            l=m+1
        else:
            h=m
    else:
        return -1
        
l=eval(input('Enter the list : '))
e=int(input('Enter the element to be searched : '))
l.sort()
print('Index of %s is %s'%(e,bin_search(l,e)))
