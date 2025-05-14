# bin file "GIFTS.DAT"
import pickle
def BUMPER():
    with open('GIFTS.dat','rb') as f:
        while True:
            try:
                x=pickle.load(f)
                if x['Remarks']=='ON DISCOUNT':
                    print('Gift Id:',x['Gift_ID'])
                    print('Name :',x['Name'])
                    print('Remarks :',x['Remarks'])
                    print('Price :',x['Price'])
            except EOFError:
                break

def TRANSFER():
    with open('GIFTS.dat','rb') as f:
        with open('G_COPY.dat','wb') as f1:
            while True:
                try:
                    x=pickle.load(f)
                    if x['Price']>500:
                        pickle.dump(x,f1)
                except EOFError:
                    break
                
