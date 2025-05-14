def PUSH_STACK(Arr,item):
    if item%2==0:
        Arr.append(item)
    if len(Arr)>0:
        for i in Arr[::-1]:
            print(i)
    else:
        print('Underflow')

def POP_STACK(Arr):
    if len(Arr)>0:
        print('Deleted element :',Arr.pop())
    else:
        print('Underflow')
