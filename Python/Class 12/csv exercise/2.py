import csv
def write():
    with open('student.csv','a',newline='') as f:
        w=csv.writer(f)
        no=int(input('Enter the roll no : '))
        name=input('Enter the name : ')
        stream=input('Enter the stream  :')
        marks=float(input('Enter the marks : '))
        w.writerow([no,name,stream,marks])

def read():
    with open('student.csv','r') as f:
        r=csv.reader(f)
        for i in r:
            print('Roll number :',i[0])
            print('Name :',i[1])
            print('Stream :',i[2])
            print('Marks :',i[3])
            next(r)
