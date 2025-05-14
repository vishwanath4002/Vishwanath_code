#1
d=eval(input('Enter the dictionary items : '))
a=eval(input('Enter the value to be checked : '))
for i in d:
    if d[i]==a:
        print('Value found at key :',i)
        break
else:
    print('Value not found.)
