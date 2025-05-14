import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759'
    database='bookshop')
cursor=mydb.cursor()

cursor.execute('select * from book')
for i in cursor:
    print(i)
