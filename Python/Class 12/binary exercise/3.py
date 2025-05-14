import pickle
def CREATE_REC():
    with open('TEACHER.dat','ab') as f:
        x=()
        x+=int(input('Enter the number : '))
        x+=input('Enter the name : ')
        x+=input('Enter the department : ')
        x+=float(input('Enter the salary : '))
        x+=input('Enter the gender : ')
        pickle.dump(x,f)
def SEARCH_REC(NAME):
    with open('TEACHER.dat','rb') as f:
        x=()
        while True:
            try:
                x+=pickle.load(f)
            except EOFError:
                break
        for i in x:
            if NAME==i[1]:
                print('No : %s\nName : %s\nDepartment : %s\nSalary : \nGender : %s'%(i[0],i[1],i[2],i[3],i[4]))
        else:
            print('Teacher name entered does not exist.')
