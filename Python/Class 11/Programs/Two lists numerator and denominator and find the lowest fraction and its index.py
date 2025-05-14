#Two lists numerator and denominator and find the lowest fraction and its index
n=[]
d=[]
f=[]
l=int(input('Enter the limit of the list : '))
print('Numerators')
for i in range(l):
    n.append(int(input('Enter a number : ')))

print(n)
print('Denominators')
for i in range(l):
    d.append(int(input('Enter a number greater than zero : ')))
print(d)
for i in range(l):
    f.append(n[i]/d[i])
print('The list of fractions is',f)
print('Smallest fraction is %s and its index is %s'%(min(f),f.index(min(f))))
