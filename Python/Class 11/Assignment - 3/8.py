#upper to lower, lower to upper
s=input('Enter the string : ')
for i in s:
    if i.isupper():
        print(i.lower(),end='')
    elif i.islower():
        print(i.upper(),end='')
    else:
        continue
