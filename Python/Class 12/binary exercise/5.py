import pickle
def CreateEmp():
    with open('emp.dat','wb') as f:
        while True:
            EID=int(input('Enter the employee id : '))
            Ename=input('Enter the name of employee : ')
            designation=input('Enter the designation : ')
            salary=int(input('Enter the salary : '))
            pickle.dump([EID,Ename,designation,salary],f)
            c=input('Do you want to continue? : ')
            if c!='yes':
                break

def display():
    with open('emp.dat','rb') as f:
        x=[]
        y=[]
        while True:
            try:
                x.append(pickle.load(f))
            except EOFError:
                break
        for i in x:
            if i[3]>30000:
                y.append(i)
        if len(y)==0:
            print('There are no employees with salary more than 30000.')
        else:
            print('Details of employees with salary more than 30000 :')
            for j in y:
                print('EID :',j[0])
                print('Ename :',j[1])
                print('Designation :',j[2])
                print('Salary :',j[3])
                print()
