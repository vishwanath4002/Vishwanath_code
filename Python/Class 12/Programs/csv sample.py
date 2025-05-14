import csv
f=open('sample.csv','r')
reader=csv.reader(f)
for i in reader:
    print(i)
f.close()

