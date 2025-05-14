import pickle
n=int(input('Enter the number of records : '))
with open('items.dat','wb+') as f:
    for i in range(n):
        d={}
        print()
        d['ItemNo']=int(input('Enter the Item number : '))
        d['ItemName']=input('Enter the Item name : ')
        d['Qty']=int(input('Enter the quantity : '))
        d['Price']=float(input('Enter the price : '))
        pickle.dump(d,f)
    f.seek(0)
    print('\nRecords:\n')
    while True:
        try:
            x=pickle.load(f)
            print('Item No: ',x['ItemNo'])
            print('Item Name: ',x['ItemName'])
            print('Quantity: ',x['Qty'])
            print('Price per item: ',x['Price'])
            print('Amount: ',x['Price']*x['Qty'])
            print()
        except EOFError:
            break
