#Enter a number and check if 0 is there in it.
a=int(input('Enter a number : '))
if str(a).find('0')==-1:
    print('There is no 0.')
else:
    print('There is 0.')
