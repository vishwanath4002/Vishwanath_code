#Write a program to implement all basic operations of stack , such as adding element
#(PUSH),removing element(POP) and displaying the stack elements(TRAVERSAL) using list.
stack=[]
n=int(input('Enter the limit : '))

def PUSH():
    if isFull():
        print('Stack overflow.')
    else:
        x=eval(input('Enter the element : '))
        stack.append(x)
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
            print(i)
def PEEK():
    if isEmpty():
        print('Stack underflow')
    else:
        print(stack[-1])
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
    if c==1:
        print()
        x=int(input('Enter the limit (max=%s): '%(n-len(stack))))
        for i in range(x):
            PUSH()
    elif c==2:
        POP()
    elif c==3:
        print('The last element is :',end=' ')
        PEEK()
    elif c==4:
        print('The elements are :')
        TRAVERSAL()
    elif c==5:
        break
    else:
        print('Invalid entry.')
    print()
