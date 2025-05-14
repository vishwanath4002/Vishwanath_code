#1
y=int(input('Enter the year : '))
if y%4==0 and y%100!=0:
    print('It is a leap year.')
else:
    print('It is not a leap year.')
