s=0
while True:
    n=int(input('Enter the number : '))
    if n>0:
        s+=n
    else:
        break
    ch=input('Do you want to continue ? :')
    if ch=='yes':
        print('Sum : %s'%s)
    else:
        break
