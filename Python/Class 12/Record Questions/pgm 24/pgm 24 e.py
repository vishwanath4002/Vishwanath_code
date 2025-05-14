import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759'
    database='bookshop')
cursor=mydb.cursor()

n=int(input('Enter the book number : '))
cursor.execute('select bookno from book')
x=fetchall()
if n in x:
    cursor.execute('delete from book where bookno=%s'%(n))
else:
    print('Record not found.')
mydb.commit()
