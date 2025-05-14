#bin search
def bin_search(l,n):
    l.sort()
    s=0
    e=len(l)-1
    while s<e:
        m=(s+e)//2
        if n==l[m]:
            return m
        elif l[m]<n:
            s=m+1
        else:
            e=m
    return -1
def bin_search_recursion(l,n,s,e):
    if e>s:
        m=(s+e)//2
        if n==l[m]:
            return m
        elif n<l[m]:
            return bin_search_recursion(l,n,s,m)
        else:
            return bin_search_recursion(l,n,m+1,e)
    else:
        return -1
l=eval(input('Enter the list : '))
a=int(input('Enter the element to be searched : '))
print(bin_search(l,a))
print(bin_search_recursion(l,a,0,len(l)))
