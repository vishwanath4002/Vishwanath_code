#To convert the time inputted in minutes to hours and remaining minutes
t=int(input("Enter the time in minutes : "))
h=t//60 #Hours
m=t%60 #Remaining minutes
if m==0:
    print("It is",h,"hours")
else:
    print("Its is",h,"hours and",m,"minutes")
