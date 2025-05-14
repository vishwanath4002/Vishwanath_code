#Count the number of times a character appears in a given string using a dictionary
a=input('Enter the string : ')
d={}
for i in a:
    d[i]=a.count(i)
print(d)
