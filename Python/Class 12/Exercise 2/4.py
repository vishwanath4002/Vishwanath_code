def mul7(l):
    for i in range(len(l)-1):
        if l[i+1]%7==0:
            l[i],l[i+1]=l[i+1],l[i]
    return l
        
