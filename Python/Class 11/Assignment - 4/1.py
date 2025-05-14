#menu with lists
s=[]
while True:
    n=int(input('\n1.Insertion\n2.Deletion\n3.Exit\n\nEnter your choice : '))
    if n==1:
        s.append(int(input('Enter the number : ')))
    elif n==2:
        if s==[]:
            print('Enter some values for the list first.')
        else:
            d=int(input('1.Value\n2.Index\n3.Slice\n4.Exit\n\nEnter your choice : '))
            if d==1:
                s.remove(int(input('Enter the value to be deleted : ')))
            elif d==2:
                s.pop(int(input('Enter the index of the element to be removed : ')))
            elif d==3:
                i,j=map(int,input('Enter the limits of the slice to be removed : ').split())
                del s[i:j]
    elif n==3:
        break
    else:
        print('Invalid entry\nTry again')
    print(s)
    print('-----------------------------------------------------')
