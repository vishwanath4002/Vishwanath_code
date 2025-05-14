from statistics import mean
a=()
n=int(input('Enter the number of terms in the tuple : '))
for i in range(n):
    a+=eval(input('Enter the term : ')),
av=sum(a)/len(a)
if av==mean(a):
    print('They are equal.')
else:
    print('They are not equal.')
