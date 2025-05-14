import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759',
    database='bookshop')
cursor=mydb.cursor()

#creating the table
#cursor.execute('create table book(bookno int, bookname varchar(20), price float, author varchar(20),publisher varchar(20))')

while True:
    c=int(input('1. Insert data\n2. Update a record.\n3. Delete a record\n4. Exit\nEnter your choice (1,2,3,4) : '))
    print()
    if c==1:
        l=()
        l+=(int(input('Enter the book number : '))),
        a=input('Enter the name of the book : ')
        a='"'+a+'"'
        l+=(a),
        l+=(eval(input('Enter the price : '))),
        a=input('Enter the name of the author : ')
        a='"'+a+'"'
        l+=(a),
        a=input('Enter the publisher : ')
        a='"'+a+'"'
        l+=(a),
        cursor.execute('insert into book values(%s,%s,%s,%s,%s)'%(l))
        mydb.commit()
        print('\nRecord inserted.')
    elif c==2:
        l=[]
        n=int(input('Enter the book number of the record to be updated : '))
        cursor.execute('select bookno from book')
        for i in cursor:
            for j in i:
                l.append(j)
        if n in l:
            a=int(input('1. Bookname\n2. Price\n3. Author\n4. Publisher\nEnter the value to be updated : '))
            if a==1:
                nn=int(input('Enter the new bookname : '))
                cursor.execute('update book set bookname=%s where bookno=%s'%(nn,n))
                mydb.commit()
            elif a==2:
                np=eval(input('Enter the new price of the book : '))
                cursor.execute('update book set price=%s where bookno=%s'%(np,n))
                mydb.commit()
            elif a==3:
                na=input('Enter the author : ')
                cursor.execute('update book set author=%s where bookno=%s'%(na,n))
                mydb.commit()
            elif a==4:
                np=int(input('Enter the publisher : '))
                cursor.execute('update book set publisher=%s where bookno=%s'%(np,n))
                mydb.commit()
            else:
                print('Invalid entry.')
                break
        else:
            print('Record not found.')

    elif c==3:
        l=[]
        n=int(input('Enter the book number of the record to be deleted : '))
        cursor.execute('select bookno from book')
        for i in cursor:
            for j in i:
                l.append(j)
        if n in l:
            cursor.execute('delete from book where bookno=%s'%(n))
            mydb.commit()
            print('Record deleted.')
        else:
            print('Record not found.')

    elif c==4:
        break

    else:
        print('Invalid entry.')
    print()
                    
            
    
