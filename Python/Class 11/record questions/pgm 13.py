#13
def n(num):
    s=num[0:3]+'-'+num[3:6]+'-'+num[6::]
    return s
    
c=0

name=input('\nEnter the name : ')

for i in name:
    if i.isalpha() or i==' ':
        c+=1
        continue
    else:
        print('\nThe name entered is invalid.')
        break

if c==len(name):
    print('\nName:',name.title())
    
num=input('\nEnter the phone number : ')

if num.isdigit() and len(num)==10:
    print('\nNumber:',n(num))

else:
    print('\nNumber entered is not valid.')
