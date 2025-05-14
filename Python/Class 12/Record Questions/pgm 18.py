import csv

def create():
    with open('Groceries.csv','w') as f:
        w=csv.writer(f)
        w.writerow(['item code','name','price','qty'])
        while True:
            code=input('Enter the Item code : ')
            name=input('Enter the item name : ')
            price=float(input('Enter the price of item : '))
            qty=int(input('Enter the quantity : '))
            print()
            w.writerow([code,name,price,qty])
            if input('Do you want to continue? : ')=='no':
                break

def displayall():
    with open('Groceries.csv','r') as f:
        print('All items:')
        r=csv.reader(f)
        next(r)
        for i in r:
            if i!=[]:
                print()
                print('Item code :',i[0])
                print('Item name :',i[1])
                print('Item price :',i[2])
                print('Quantity :',i[3])

def display500():
    with open('Groceries.csv','r') as f:
        print('Items with price greater than 500:')
        r=csv.reader(f)
        next(r)
        for i in r:
            if i!=[]:
                if float(i[2])>500:
                    print()
                    print('Item code :',i[0])
                    print('Item name :',i[1])
                    print('Item price :',i[2])
                    print('Quantity :',i[3])

while True:
    c=int(input('1. Create the file\n2. Display all items\n3. Display items with price greater than 500\n4. Exit\nEnter your choice : '))
    print()
    if c==1:
        create()
    elif c==2:
        displayall()
    elif c==3:
        display500()
    elif c==4:
        break
    else:
        print('Invalid entry.')
    print()


