e={}
ta=0
td=0
for in range(10):
    n=input('Enter the name : ')
    s=float(input('Enter the salary : '))
    a=float(input('Enter the allowance : '))
    d=float(input('Enter the deduction : '))
    e[n]=[s,a,d]

while True:
    print('a) Display total salary')
    print('b) Display total allowance and deductions')
    print('c) Search an employee')
    print('d) Exit')
    c=int(input('Enter your choice : '))
    print()
    if c==1:
        for i in e.keys():
            print('Employee name :',i)
            print('Total salary =',e[i][0]+e[i][1]-e[2])
            ta+=e[1]
            td+=e[2]
            print()
    elif c==2:
        print('Total allowance =',ta)
        print('total deductions =',td)
        print()
    elif c==3:
        name=input('Enter the name to be searched : ')
        if name in e.keys():
            print('Salary :',e[name][0])
            print('Allowance :',e[name][1])
            print('Deductions :',e[name][2])
        else:
            print('Not found.')
        print()
    elif c==4:
        break
    else:
        print('Invalid entry.')
        print()


        
