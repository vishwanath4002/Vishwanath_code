#Count the number of digits,alphabets and special caracter in a string entered by the user
s=input('Enter the string : ')
d=0
a=0
spec=0
for i in range(len(s)):
    if s[i].isalpha():
        a+=1
    elif s[i].isdigit():
        d+=1
    else:
        spec+=1
print('Number of alphabets : %s\nNumber of digits : %s\nNumber of special characters : %s'%(a,d,spec))
