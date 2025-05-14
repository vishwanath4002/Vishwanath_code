#A text file contains a list of contact numbers in the following form
#"name number" (aakash 9446755727). Write a program to read and display its
#contents in two columns
import csv
with open('text.txt','w') as f:
    f.write('vishwanath 2132323213\naakash 9446755727')
    
with open('text.txt','r') as f1:
    with open('columns.csv','w',newline='') as f2:
        w=csv.writer(f2,delimiter='\t')
        while True:
            try:
                x=f1.readline()
                if x!='':
                    x=x.split()
                    w.writerow(x)
                else:
                    break
            except EOFError:
                break
            
with open('columns.csv','r') as f3:
    r=csv.reader(f3)
    for i in r:
        print(i)
