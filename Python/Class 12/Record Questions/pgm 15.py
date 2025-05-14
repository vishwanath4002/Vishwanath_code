import pickle
def Create(n):
    d={}
    with open('inventory.dat','wb') as f:
        for i in range(n):
            print()
            d['ItemCode']=int(input('Enter the Item Code : '))
            d['ItemName']=input('Enter the name : ')
            d['ItemCost']=float(input('Enter the Item cost : '))
            pickle.dump(d,f)

def Search(e):
    with open('inventory.dat','rb') as f:
        while True:
            try:
                x=pickle.load(f)
                if e==list(x.values())[0]:
                    print('Record exists.\nDetails:')
                    print('Item code :',x['ItemCode'])
                    print('Item name :',x['ItemName'])
                    print('Item cost :',x['ItemCost'])
                    return
            except EOFError:
                break
        print('Not found.')

def Display():
    with open('inventory.dat','rb') as f:
        print('Details:')
        c=True
        while True:
            try:
                x=pickle.load(f)
                print()
                print('Item code :',x['ItemCode'])
                print('Item name :',x['ItemName'])
                print('Item cost :',x['ItemCost'])
                c=False
            except EOFError:
                break
        if c:
            print('No existing records.')
while True:
    c=int(input('1.Create the File\n2.Search\n3.Display\n4.Exit\nEnter your choice : '))
    print()
    if c==1:
        n=int(input('Enter the number of items : '))
        Create(n)
        print('Item records created.')

    elif c==2:
        e=int(input('Enter the Item code to be searched : '))
        Search(e)

    elif c==3:
        Display()

    elif c==4:
        break

    else:
        print('Invalid entry. Please try again.')
    print()
