'''d={}
n=int(input('Enter the limit : '))
for i in range(n):
    x={}
    x['name']=input('Enter the name : ')
    x['dept']=input('Enter the department : ')
    x['Salary']=float(input('Enter the salary : '))
    x['Contact number']=input('Enter the contact number : ')
    d[i+1]=x'''

def shortest(l):
    m=l[0]
    for i in l:
        if len(i)<len(m):
            m=i
        else:
            continue
    print(m)
        
def doubleodd(l):
    for i in range(len(l)):
        if l[i]%2!=0:
            l[i]*=2
        else:
            continue

def Lshift(Arr,n):
    for i in range(n):
        Arr.append(Arr[0])
        Arr.pop(0)
    print(Arr)

def swap(l):
    f=False
    for i in range(len(l)-1):
        if f==True:
            f=False
            continue
        else:
            if l[i]%7==0:
                if f==False:
                    l[i],l[i+1]=l[i+1],l[i]
                    f=True
            else:
                f=False
    print(l)

def signalign(l):
    p=[]
    n=[]
    for i in l:
        if i<0:
            n.append(i)
        else:
            p.append(i)
    l=n+p
    print(l)

n=int(input('Enter the quantity : '))
a=n*100
if n>50:
    d=a*0.1
elif n<50 and n>30:
    d=a*0.05
else:
    d=0
print('Discount : %s\nBill amount : %s'%(d,a-d))
    
def checkpalindrome(s):
    a=''
    for i in range(len(s)-1,-1,-1):
        a+=s[i]
    if s==a:
        return True
    else:
        return False
