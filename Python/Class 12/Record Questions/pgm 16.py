import pickle
import os
def Create(n):
    with open('employee.dat','wb') as f:
        for i in range(n):
            d={}
            print()
            d['EmpId']=int(input('Enter the employee Id : '))
            d['EmpName']=input('Enter the name of employee : ')
            d['Salary']=float(input('Enter the salary : '))
            pickle.dump(d,f)

def Update(e):
    with open('employee.dat','rb') as f:
        with open('temp.dat','wb') as f1:
            while True:
                try:
                    x=pickle.load(f)
                    if e==list(x.values())[0]:
                        x['Salary']=float(input('Enter new salary : '))
                        print('Record updated.')
                        pickle.dump(x,f1)
                    else:
                        pickle.dump(x,f1)
                except EOFError:
                    break
    os.remove('employee.dat')
    os.rename('temp.dat','employee.dat')
        
def Display():
    with open('employee.dat','rb') as f:
        print('Records:')
        while True:
            try:
                x=pickle.load(f)
                print()
                print('Employee Id :',x['EmpId'])
                print('Name of employee :',x['EmpName'])
                print('Salary :',x['Salary'])
            except EOFError:
                break
while True:
    print()
    c=int(input('1.Create the file\n2.Update\n3.Display\n4.Exit\nEnter your choice : '))
    print()
    if c==1:
        n=int(input('Enter the number of employees : '))
        Create(n)
        print('Records created.')

    elif c==2:
        x=int(input('Enter the Id of the employee to be updated : '))
        Update(x)

    elif c==3:
        Display()

    elif c==4:
        break

    else:
        print('Invalid entry. Please try again.')
