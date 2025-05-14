import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759',
    database='test'
    )
cursor=mydb.cursor()
cursor.execute('create table b(a int)')

