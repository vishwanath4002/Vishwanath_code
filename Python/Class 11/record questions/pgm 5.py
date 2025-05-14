#5
n=int(input('Enter the number : '))
s=0
for i in str(n):
    s+=int(i)
print('Sum of digits :',s)
r=int(str(n)[::-1])
print('Reverse :',r)
if r==n:
    print('It is a palindrome.')
else:
    print('It is not a palindrome.')
