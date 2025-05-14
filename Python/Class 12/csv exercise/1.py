import csv
with open('employee.csv','a',newline='') as f:
    while True:
        writer=csv.writer(f)
        no=int(input('Enter the employee number : '))
        name=input('Enter the name : ')
        salary=float(input('Enter the salary : '))
        writer.writerow([no,name,salary])
        c=input('Do you want to continue? : ')
        if c=='no':
            break
