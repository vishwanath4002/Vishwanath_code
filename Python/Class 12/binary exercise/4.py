import pickle
with open('STORE.dat','wb') as f:
    pickle.dump((1,'a',12,1241),f)
    pickle.dump((2,'b',123,1242),f)
    pickle.dump((3,'c',35,122),f)
    pickle.dump((4,'d',14,412),f)
    pickle.dump((5,'e',133,1212),f)
    
def Display_Rec():
    with open('STORE.dat','rb') as f:
        x=()
        t=()
        while True:
            try:
                x+=pickle.load(f),
            except EOFError:
                break
        for i in x:
            if i[2]>35:
                t+=i,
        if len(t)==0:
            print('There are no items with quantity greater than 35.')
        else:
            print('Details of items with quantity greater than 35:')
            for j in t:
                print('Item id :',j[0])
                print('Item name :',j[1])
                print('Quantity :',j[2])
                print('Price :',j[3])
                print()
            print('Total number of records in the file is %s.'%(len(x)))
