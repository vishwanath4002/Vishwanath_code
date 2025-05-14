#Count number of vowels in a string
a=input('Enter the string : ')
v='AEIOUaeiou'
c=0
for i in range(len(a)):
    if a[i] in v:
        c+=1
print(c)
