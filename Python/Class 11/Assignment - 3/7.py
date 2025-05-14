#Check for palindrome without string slice
s=input('Enter the string : ')
r=''
for i in range(1,len(s)+1):
    r+=s[-i]
if r==s:
    print('%s is a Palindrome.'%s)
else:
    print('%s is not a palindrome.'%s)
