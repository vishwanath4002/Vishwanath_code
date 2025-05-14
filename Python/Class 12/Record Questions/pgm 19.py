def PUSH(stack):
    if len(stack)<l:
        while len(stack)<l:
            print()
            member_id=int(input('Enter the ID : '))
            name=input('Enter the name : ')
            age=int(input('Enter the age : '))
            stack.append([member_id,name,age])
            print()
            if len(stack)<l:
                c=input('Do you want to continue? : ')
                if c!='yes':
                    break
    else:
        print('Stack overflow.')
    return stack

def POP(stack):
    if len(stack)>0:
        stack.pop()
    else:
        print('Stack underflow.')
    return stack

def display():
    for i in range(len(stack)-1,-1,-1):
        print()
        print('Member ID :',stack[i][0])
        print('Member name :',stack[i][1])
        print('Member age :',stack[i][2])


stack=[]
l=int(input('Enter the limit of the stack : '))
while True:
    print()
    c=int(input('1.PUSH\n2.POP\n3.Display\n4.Exit\nEnter your choice : '))
    if c==1:
        stack=PUSH(stack)
    elif c==2:
        stack=POP(stack)
    elif c==3:
        display()
        print()
    elif c==4:
        break
    else:
        print('Invalid entry. Please try again.')
