#q 42
import pickle
with open('PRODUCT.dat','wb+') as f:
    while True:
        d={}
        d['prod_code']=input('prod_code: ')
        d['prod_desc']=input('prod_desc: ')
        d['stock']=int(input('stock: '))
        pickle.dump(d,f)
        c=input('Do you want to continue : ')
        if c=='no':
            break
    with open('PRODUCT.dat','wb') as f1:
        f.seek(0)
        code=input('Enter the product code to be udpated : ')
        while True:
            try:
                x=pickle.load(f)
                if x['prod_code']==code:
                    x['stock']=int(input('Enter the new stock : '))
                    print('Record Updated')
                pickle.dump(x,f1)
            except EOFError:
                break


