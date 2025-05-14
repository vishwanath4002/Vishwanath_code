import csv
def single():
    with open('student.csv','a',newline='') as f:
        print()
        w=csv.writer(f)
        no=int(input('Enter the roll no : '))
        name=input('Enter the name : ')
        stream=input('Enter the stream  :')
        marks=float(input('Enter the marks : '))
        w.writerow([no,name,stream,marks])

def together():
    y=[]
    while True:
        x=[]
        print()
        x.append(input('Enter the roll no : '))
        x.append(input('Enter the name : '))
        x.append(input('Enter the stream  :'))
        x.append(float(input('Enter the marks : ')))
        y.append(x)
        c=input('Do you want to continue? : ')
        if c=='no':
            break
    with open('student.csv','a',newline='') as f:
        w=csv.writer(f)
        w.writerows(y)

def display():
    with open('student.csv','r') as f:
        r=csv.reader(f)
        for i in r:
            if i!=[]:
                print()
                print('Roll number :',i[0])
                print('Name :',i[1])
                print('Stream :',i[2])
                print('Marks :',i[3])


while True:
    print()
    c=int(input('1.Write single record\n2.Write all records in one go\n3.Display\n4.exit\nEnter your choice : '))
    if c==1:
        single()

    elif c==2:
        together()

    elif c==3:
        display()

    elif c==4:
        break

    else:
        print('Invalid entry. Please try again')
        
