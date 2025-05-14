#write employee details(name, id, salary) for n employees
import pickle
with open('emp.dat','wb+') as f:
    for i in range(int(input('Enter the number of employees : '))):
        name=input('Enter the name : ')
        Id=int(input('Enter the id : '))
        sal=eval(input('Enter the salary : '))
        pickle.dump([name,Id,sal],f)
    f.seek(0)
    with open('epm.dat','wb+') as f1:
        while True:
            try:
                x=pickle.load(f)
                if x[2]<40000:
                    pickle.dump(x,f1)
            except EOFError:
                break
        f1.seek(0)
        print(pickle.load(f1))
        f1.seek(0)
        y=[]
        while True:
            try:
                x=pickle.load(f1)
                if x[1]==1:
                    x[0]='Aakash'
                y.append(x)
            except EOFError:
                break
        with open('epm.dat','wb+') as f2:
            for i in y:
                pickle.dump(i,f2)
            f2.seek(0)
            while True:
                try:
                    print(pickle.load(f))
                except EOFError:
                    break
        
    
