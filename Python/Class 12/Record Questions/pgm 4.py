def linearsearch(l,e):
        for i in range(len(l)):
            if l[i]==e:
                return i
        return -1

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

while True:
    c=int(input('\n1.Linear search.\n2.Binary search.\n3.Exit\nEnter your choice (1,2,3): '))
    print()
    l=[]
    if c==1:
        n=int(input('Enter the number of terms : '))
        print('Enter the elements : ')
        for i in range(n):
            l.append(int(input('Element %s : '%(i+1))))
        e=int(input('Enter the element to be searched : '))
        if linearsearch(l,e)==-1:
            print('%s not found in the list.'%e)
        else:
            print('%s found at index %s.'%(e,linearsearch(l,e)))

    elif c==2:
        n=int(input('Enter the number of terms : '))
        print('Enter the elements : ')
        for i in range(n):
            l.append(int(input('Element %s : '%(i+1))))
        e=int(input('Enter the element to be searched : '))
        if bin_search(l,e)==-1:
            print('%s not found in the list.'%e)
        else:
            print('%s found at index %s.'%(e,bin_search(l,e)))

    elif c==3:
        break

    else:
        print('Invalid entry. Please try again.')
