#16
s=0

l=eval(input('Enter a list : '))
l.sort()
print('\nThe largest number in the list is %s.\nThe smallest number in the list is %s.\nThe third largest number in the list is %s.'%(l[-1],l[0],l[-3]))

n=eval(input('\nEnter the number to print the multiplication table of : '))
print('\nMultiplication table of',n,'\n')

for i in range(1,11):
    print('%s X %s  = %s'%(n,i,n*i))

l1=eval(input('\nEnter a list : '))
for i in l1:
    if i%2==0:
        s+=i
print('\nThe sum of all the even numbers in the list %s is %s.'%(l1,s))
