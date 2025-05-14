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
    print('Enter the new details:\n')
    b_n=input('Enter the book name : ')
    b_p=eval(input('Enter the price : '))
    b_a=input('Enter the author : ')
    b_h=input('Enter the publisher : ')
    cursor.execute('update book set bookname=%s, price=%s, author=%s ,publisher=%s where bookno=%s'%(u_n,u_p,u_a,u_h,n))
else:
    print('Record not found.')
mydb.commit()

