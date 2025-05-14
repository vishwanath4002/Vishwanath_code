#WAP tat capitalizes every other character in the string
s=input('Enter the string : ')
for i in range(len(s)):
    if i%2==0:
        print(s[i].lower(),end='')
    else:
        print(s[i].upper(),end='')
