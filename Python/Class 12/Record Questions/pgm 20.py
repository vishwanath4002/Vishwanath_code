def enqueue(q):
    if len(q)<n:
        while len(q)<n:
            cust_id=int(input('Enter the Customer ID : '))
            cust_name=input('Enter the Customer name : ')
            ph_num=int(input('Enter the phone number : '))
            q.append([cust_id,cust_name,ph_num])
            print()
            if len(q)!=n:
                c=input('Do you want to continue : ')
                if c.lower()!='yes':
                    break
    else:
        print('Queue overflow.')
    return q

def dequeue(q):
    if len(q)>0:
        del q[-1]
    else:
        print('Queue underflow.')
    return q
def display(q):
    if len(q)>0:
        for i in q:
            print()
            print('Customer ID :',i[0])
            print('Customer Name :',i[1])
            print('Phone number :',i[2])
    else:
        print('Queue is empty.')
    
queue=[]
n=int(input('Enter the limit : '))
while True:
    print()
    c=int(input('1.ENQUEUE\n2.DEQUEUE\n3.Display\n4.Exit\nEnter your choice : '))
    print()
    if c==1:
        queue=enqueue(queue)
        print('The element at the front end :',queue[0])
        print('The element at the rear end :',queue[-1])
    elif c==2:
        queue=dequeue(queue)
    elif c==3:
        display(queue)
    elif c==4:
        break
    else:
        print('Invalid entry.')
        
