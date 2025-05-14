import csv
    with open('Groceries.csv','a',newline='') as f:
        w=csv.writer(f)
        while True:
            code=int(input('Enter the code : '))
            name=input('Enter the name : ')
            price=float(input('Enter the price : '))
            qty=int(input('Enter the quantity : '))
            w.writerow([code,name,price,qty])
            c=input('Do you want to continue? : ')
            if c.lower()=='no':
                break
