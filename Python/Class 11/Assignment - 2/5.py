'''WAP to print wheter a given character is an upper case or
a lower case or a digit or any other character'''

a=input('Enter a character : ')
if a>='A' and a<='Z':
    print('It is upper case.')
elif a>='a' and a<='z':
    print('It is lower case.')
elif a>='0' and a<='9':
    print('It is a digit.')
else:
    print('It is a special character.')
