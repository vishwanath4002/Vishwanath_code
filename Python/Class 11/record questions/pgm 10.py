#10
s=input('Enter the string : ')
v=0
c=0
d=0
sp=0
spec=0

while True:

    ch=int(input('1.Number of vowels, consonants, digits, spaces and special characters\n2.String length and in toggled case\n3.Number of words\n4.Exit.\nEnter your choice (1, 2, 3 or 4) : '))

    if ch==1:

        for i in s:
            if i.lower() in 'aeiou':
                v+=1
            elif i.lower() in 'bcdfghjklmnpqrstvwxyz':
                c+=1
            elif i.isdigit():
                d+=1
            elif i==' ':
                sp+=1
            else:
                spec+=1
        print('\nNumber of vowles : %s\nNumber of consonants : %s\nNumber of digits : %s\nNumber of spaces : %s\nNumber of special characters : %s'%(v,c,d,sp,spec))

    elif ch==2:

        print('\nThe length of the string is :',len(s))
        ch1=int(input('\n1.Sentence case\n2.Title case\n3.Uppercase\n4.Lowercase\nEnter your choice (1, 2, 3 or 4) : '))

        if ch1==1:
            print('Sentence case :',s.capitalize())
        elif ch==2:
            print('Title case :',s.title())
        elif ch==3:
            print('Uppercase :',s.upper())
        elif ch==4:
            print('Lowercase :',s.lower())
        else:
            print('\nInvalid entry.')
            
    elif ch==3:
        print('\nThe number of words is :',len(s.split()))

    elif ch==4:
        break

    else:
        print('\nInvalid entry.')
