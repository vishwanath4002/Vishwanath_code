import pickle
def Add_Mobile():
    with open('Mobile.dat','wb') as f:
        while True:
            x=[]
            x.append(input('Enter the model : '))
            x.append(input('Enter the company : '))
            x.append(float(input('Enter the price : ')))
            pickle.dump(x,f)
            c=input('Do you want to continue? : ')
            if c!='yes':
                break
def count_company(c):
    with open('Mobile.dat','rb') as f:
        n=0
        x=[]
        while True:
            try:
                x.append(pickle.load(f))
            except EOFError:
                break
        for i in x:
            if i[1]==c:
                n+=1
        print('Number of mobiles of company %s is : %s'%(c,n))
Add_Mobile()
count_company('redmi')
 
