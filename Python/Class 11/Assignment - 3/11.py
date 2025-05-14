#WAP input a string and find the sum of digits in  the string
s=input('Enter the string : ')
d=0
for i in s:
    if i.isdigit():
        d+=int(i)
print('The sum of digits in the string is',d)
