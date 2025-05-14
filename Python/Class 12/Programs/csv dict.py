import csv
f=open('sample.csv','w',newline='')
fields=['name','roll','marks']
writer=csv.DictWriter(f,fieldnames=fields)
writer.writeheader()
writer.writerow({'name':'asasdas','roll':1,'marks':69})
f.close()
with open('sample.csv','r') as f:
    r=csv.DictReader(f)
    for i in r:
        print(i)
