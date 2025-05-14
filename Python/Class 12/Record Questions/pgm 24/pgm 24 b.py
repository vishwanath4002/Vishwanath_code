import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759'
    database='bookshop')
cursor=mydb.cursor()

n=int(input('Enter the limit : '))
for i in range(n):
    b_n=int(input('Enter the book no : '))
    b_m=input('Enter the book name : ')
    b_p=eval(input('Enter the price : '))
    b_a=input('Enter the author : ')
    b_h=input('Enter the publisher : ')
    cursor.execute('insert into book values(%s,%s,%s,%s,%s)'%(b_n,b_m,b_p,b_a,b_h))
mydb.commit()
