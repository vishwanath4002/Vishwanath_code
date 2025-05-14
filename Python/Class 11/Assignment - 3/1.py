#WAP to count all lower case, upper case, digits, and special symbols from a given string
s=input('Enter the string : ')
d=0
u=0
l=0
spec=0
space=0
for i in range(len(s)):
    if s[i].isupper():
        u+=1        
    elif s[i].islower():
        l+=1
    elif s[i].isdigit():
        d+=1
    elif s[i].isspace():
        space+=1
    else:
        spec+=1
print('Number of Upper case characters  : %s\nNumber of Lower case characters : %s\nNumber of digits : %s\nNumber of special characters : %s\nNumber of Spaces : %s'%(u,l,d,spec,space))
