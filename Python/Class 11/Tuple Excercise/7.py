a=()
b=()
n=int(input('Enter the number of terms in the first tuple : '))
for i in range(n):
    a+=eval(input('Enter the term : ')),
m=int(input('Enter the number of terms in the second tuple : '))
for i in range(m):
    b+=eval(input('Enter the term : ')),
for i in a:
    if i not in b:
        print('False')
        break
    else:
        print('True')
