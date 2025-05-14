'''Write a menu based program to perform push and pop operations on a Stack.
Each node of the Stack contains the following Member’s details as given below:
Member id integer
Member Name string
Age integer'''

stack=[]
n=int(input('Enter the limit : '))

def PUSH():
    if isFull():
        print('Stack overflow.')
    else:
        l=[]
        l.append(int(input('Enter the Member Id : ')))
        l.append(input('Enter the Member name : '))
        l.append(int(input('Enter the age : ')))            
        stack.append(l)
def POP():
    if isEmpty():
        print('Stack underflow.')
    else:
        stack.pop()
def TRAVERSAL():
    if isEmpty():
        print('Stack underflow')
    else:
        for i in stack[::-1]:
            print('Member Id : %s\nMember Name : %s\nAge : %s\n'%(i[0],i[1],i[2]))
            
def PEEK():
    if isEmpty():
        print('Stack underflow')
    else:
        print('Member Id : %s\nMember Name : %s\nAge : %s\n'%(stack[-1][0],stack[-1][1],stack[-1][2]))
def isFull():
    if len(stack)==n:
        return True
    else:
        return False
def isEmpty():
    if len(stack)==0:
        return True
    else:
        return False

while True:
    print('1.Push\n2.Pop\n3.Peek\n4.Traversal\n5.Exit')
    c=int(input('Enter your choice : '))
    print()
    if c==1:
        print()
        if isFull():
            print('Stack overflow.')
            continue
        x=int(input('Enter the limit (max=%s): '%(n-len(stack))))
        for i in range(x):
            if isFull():
                print('Stack overflow.')
                continue
            PUSH()
    elif c==2:
        POP()
    elif c==3:
        print('The last element is :')
        PEEK()
    elif c==4:
        print('The elements are :')
        TRAVERSAL()
    elif c==5:
        break
    else:
        print('Invalid entry.')
    print()
