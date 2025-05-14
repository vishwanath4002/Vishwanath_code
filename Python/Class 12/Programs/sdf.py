
'''def sumOfNumbers(l,a):
    s=0
    if '-' in l:
        l.remove('-')
        for i in l:
            if i<0:
                s+=i
        return s
    else:
        if '+' in l:
            l.remove('+')
        for i in l:
            if i>0:
                s+=i
        return s'''
        


def sumOfNumbers(l,a='+'):
    s=0
    if a=='-':
        for i in l:
            if i<0:
                s+=i
    else:
        for i in l:
            if i>0:
                s+=i
    return s

def prime(l):
    a=[]
    for i in l:
        for j in range(2,i):
            if i%j==0:
                break
        else:
            a.append(i)
    return a
print(prime([1,3,6,7,5]))

def even(a,b):
    l=[]
    for i in range(a,b):
        if i%2==0:
            l.append(i)
        else:
            continue
    return l
print(even(1,20))

def reverse(a):
    return a[::-1]

print(reverse('hello'))

def maximum(l):
    return max(l)

print(maximum([1,3,6,7,5]))

def unique(l):
    a=[]
    for i in l:
        if i not in a:
            a.append(i)
    return a
print(unique([1,2,3,2,1,1,3,4,2]))

            

