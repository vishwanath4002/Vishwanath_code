#Read alphanumeric and print only integers
s=input('Enter an alphanumeric string : ')
for i in s:
    if i.isdigit():
        print(i,end='')
