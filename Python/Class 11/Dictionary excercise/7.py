#7
d={}
while True:
    i=int(input('\n1.Insertion\n2.Deletion\n3.Search\n4.Updation\n5.Display.\n6.Exit\nEnter your choice : '))
    if i==1:
        r=int(input('\nEnter the roll number : '))
        d[r]=input('Enter the name : ')
    elif i==2:
        r=int(input('\nEnter the roll numer to be deleted : '))
        if r in d.keys():
            del d[r]
        else:
            print('Selected roll number does not exist.')
    elif i==3:
        s=int(input('\nSearch based on :\n1.Key\n2.Value\nEnter your choice : '))
        if s==1:
            r=int(input('\nEnter the roll number to be searched : '))
            d.get(r,'Not found')
        elif s==2:
            n=input('\nEnter the name to be searched : ')
            for i in d:
                if d[i]==n:
                    print('The roll number is :',i)
                    break
            else:
                print('Not found.')        
        else:
            print('\nInvalid entry.')
    elif i==4:
        r=int(input('\nEnter the roll number  to be updated : '))
        d[r]=input('Enter the new name : ')
    elif i==5:
        print(d)
    elif i==6:
        break
    else:
        print('\nInvalid entry.')
