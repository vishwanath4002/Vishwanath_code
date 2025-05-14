import pickle
def Add_Records():
    with open('emp.dat','ab') as f:
        EID=int(input('Enter the employee id : '))
        Ename=input('Enter the name of employee : ')
        designation=input('Enter the designation : ')
        salary=int(input('Enter the salary : '))
        pickle.dump((EID,Ename,designation,salary),f)

def Show():
    with open('emp.dat','rb') as f:
        x=()
        y=()
        while True:
            try:
                x+=pickle.load(f),
            except EOFError:
                break
        for i in x:
            if i[2]=='Salesman':
                y+=i,
        if len(y)==0:
            print('There are no employees with designation Salesman.')
        else:
            print('Details of employees with designation Salesman :')
            for j in y:
                print('EID :',j[0])
                print('Ename :',j[1])
                print('Designation :',j[2])
                print('Salary :',j[3])
                print()

        
