#Write a menu driven program which displays options for inserting or deleting elements in a list.
#If the user chooses a deletion option, display a sub menu and ask if the element to be deleted with value or by using its position or a list slice is to be deleted.
l=list()
ch='yes'
while ch.lower()=='yes':
    c=int(input('\n1.Insert\n2.Deletion\n3.Exit\nEnter your choice : '))
    if c==1:
        l.append(eval(input('Enter the element : ')))
    elif c==2:
        if l==[]:
            print('No values to delete. Enter some values first.')
        else:
            m=int(input('1.Using value\n2.Using position\n3.Delete slice\n4.Exit\n Enter your choice : '))
            if m==1:
                l.remove(eval(input('Enter the element to be deleted : ')))
            elif m==2:
                l.pop(int(input('Enter the index of the value to be deleted : ')))
            elif m==3:
                a,b=map(int,input('Enter the lower and upper limit of the slice : ').split())
                del l[a:b]
            elif m==4:
                continue
            else:
                print('Invalid entry.')            
    else:
        print('Invalid entry.')
    print(l,'\n')
    ch=input('Do you want to continue (yes/no) : ')
    
