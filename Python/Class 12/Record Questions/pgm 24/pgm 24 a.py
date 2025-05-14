import mysql.connector
mydb=mysql.connector.connect(
    host='localhost',
    user='root',
    password='1125899839733759')
cursor=mydb.cursor()
cursor.execute('CREATE DATABASE if not exists bookshop')
cursor.execute('create table book(bookno int, bookname varchar(20), price float, author varchar(20),publisher varchar(20))')
