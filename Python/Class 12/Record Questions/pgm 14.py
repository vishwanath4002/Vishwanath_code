import pickle
def Create(n):
    d={}
    with open('student.dat','wb') as f:
        for i in range(n):
            print()
            d['S_RollNo']=int(input('Enter the roll number : '))
            d['S_Name']=input('Enter the name : ')
            d['English']=float(input('Enter the English marks : '))
            d['Mathematics']=float(input('Enter the Mathematics marks : '))
            d['Science']=float(input('Enter the Science marks : '))
            pickle.dump(d,f)

def Append(n):
    d={}
    with open('student.dat','ab') as f:

        for i in range(n):
            print()
            d['S_RollNo']=int(input('Enter the roll number : '))
            d['S_Name']=input('Enter the name : ')
            d['English']=float(input('Enter the English marks : '))
            d['Mathematics']=float(input('Enter the Mathematics marks : '))
            d['Science']=float(input('Enter the Science marks : '))
            pickle.dump(d,f)
def Display():
    print('\nStudent details:')
    with open('student.dat','rb') as f:
        while True:
            try:
                x=pickle.load(f)
                print('\nRoll number : ',x['S_RollNo'])
                print('Name : ',x['S_Name'])
                print('Total marks : ',x['English']+x['Mathematics']+x['Science'])
                print()
            except EOFError:
                break
while True:
    c=int(input('1. Create the File\n2. Append\n3. Display\n4. Exit\nEnter your choice : '))
    if c==1:
        n=int(input('Enter the number of students : ')) 
        Create(n)
        print('Student records created.')

    elif c==2:
        n=int(input('Enter the number of students to be appended : '))
        Append(n)
        print('New student records created.')
    elif c==3:
        Display()

    elif c==4:
        break

    else:
        print('Invalid entry. Please try again.')
    print()
                
            
                
