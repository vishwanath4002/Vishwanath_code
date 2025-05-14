print('Enter the number to check for a three digit armstrong number.')
n=int(input('Enter the three digit number : ')) 
s=0
cpy=n
while n>0:
    d=n%10
    s+=d**3
    n=n//10
if s==cpy:
    print('%s is an armstrong number.'%cpy)
else:
    print('%s is not an armstrong number.'%cpy)
