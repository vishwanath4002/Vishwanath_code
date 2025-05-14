#WAP read a string and display the longest substring of the given string
s=input('Enter the string : ').split()
m=0
for i in s:
    if len(i)>m:
        m=len(i)
        l=i
print(l)
