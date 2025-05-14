#18
def prime(n):
    if n!=0 and n!=1:
        for i in range(2,n):
            if n%i==0:
                return False
                break
        else:
            return True
    else:
        return False

def vowel(a):
    for i in a:
        if i.lower() in 'aeiou':
            v.append(i)
    
t=()
p={}
v=[]

for i in range(1,11):

    t+=eval(input('Enter element %s : '%(i))),

for i in t:

    if type(i)==int:

        if prime(i):
            p[i]=t.count(i)
        else:
            continue

    if type(i)==str:

        vowel(i)

print()
if len(p)!=0:
    print('Prime numbers and their count.')
    for i in p.keys():
        print('%s -> count : %s'%(i,p[i]))
else:
    print('There are no prime numbers.')

print()
if len(v)!=0:
    print('Strings with at least one vowel.')
    for i in v:
        print(i)

else:
    print('There are no strings with at least one vowel.')            
