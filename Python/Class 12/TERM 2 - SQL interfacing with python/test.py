import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759',
    database='bookshop')

cursor=mydb.cursor()
#cursor.execute('create table book(bookno int, bookname varchar(20), price float, author varchar(20),publisher varchar(20))')
'''cursor.execute('insert into book values(%s,%s,%s,%s,%s)'%(1, '"Dictionary"', 420, '"Oxford"', '"Penguin"'))
mydb.commit()
cursor.execute('update book set price=69 where bookno=1')
mydb.commit()'''
cursor.execute('delete from book where bookno=1')
mydb.commit()
