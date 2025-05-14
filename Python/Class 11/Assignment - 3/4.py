#Write a program to read a string and arrange the string character such that the
#lower case letters come first
s=input('Enter the string : ')
u,l='',''
for i in s:
    if i.isupper():
        u+=i
    elif i.islower():
        l+=i
    else:
        continue
print('The converted string is : ',l+u)
