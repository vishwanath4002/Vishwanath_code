#17
def oddoreven(n):
    if n%2==0:
        return int(n/2)
    else:
        return (3*n+1)

def armstrong(n):
    s=0
    for i in str(n):
        s+=int(i)**3
    if s==n:
        return True
    else:
        return False
        

t=()
for i in range(10):
    t+=int(input('Enter element %s : '%(i+1))),

print()
for i in t:
     print(oddoreven(i))

l=None
s=None

for i in t:
    if armstrong(i):
        if l==None and s==None:
            l=s=i
        elif i<s:
            s=i
        elif i>l:
            l=i
print('\nMax : %s \nMin : %s'%(l,s))
