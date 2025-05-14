#Write a Python program that
#a)creates a tuple storing the first 9 terms of Fibonacci series.
#b)Read an element from the tuple and returns the number telling which term it is.
t=()
a,b=0,1
for i in range(9):
    t+=a,
    c,a=a+b,b
    b=c
print(t)
n=int(input('Enter the number to be searched : '))
if n in t:
    print('%s is term %s.'%(n,(t.index(n)+1)))
else:
    print('It is not present.')
