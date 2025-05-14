#15
l=eval(input('Enter a list containing 5 names of fruits : '))
print(l)

while True:
    
    print('\n1.Sort the list before and after the sort.')
    print('2.Insert a fruit at the desired position and display the list.')
    print('3.Check if a fruit is present.\n4.Exit.')

    c=int(input('\nEnter your choice : '))

    if c==1:

        print('\nList before sorting : %s\nList after sorting : %s'%(l,sorted(l)))

    elif c==2:

        l.insert(int(input('\nEnter the index at which to insert : ')),input('Enter the new name to be inserted : '))
        print(l)

    elif c==3:

        i=input('\nEnter the fruit to be searched : ')
        count=0
        for j in l:
            if i==j:
                print('Fruit found at index %s.'%(count))
                break
            else:
                count+=1
        else:
            print('Fruit not found.')
            
    elif c==4:

        break
    
    else:
        print('\nInvalid entry.')
