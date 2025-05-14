#calculator

def add(a,b):
    print('%s + %s = %s'%(a,b,a+b))
def sub(a,b):
    print('%s - %s = %s'%(a,b,a-b))
def div(a,b):
    print('%s / %s = %s'%(a,b,a/b))
def mul(a,b):
    print('%s X %s = %s'%(a,b,a*b))
'''a,b=map(eval,input('Enter the numbers : ').split())
print('1.Addition\n2.Subtraction\n3.Division\n4.Multiplication\n')
ch=int(input('Enter your choice : '))
if ch==1:
    add(a,b)
elif ch==2:
    sub(a,b)
elif ch==3:
    div(a,b)
elif ch==4:
    mul(a,b)
else:
    print('Invalid choice')'''
