import csv
with open('sample.csv','r') as f:
    w=csv.DictReader(f)
    print(dict(w))

    
