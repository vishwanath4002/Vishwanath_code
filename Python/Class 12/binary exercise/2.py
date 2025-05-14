import pickle
with open('ATTENDANCE.dat','wb') as f:
    pickle.dump([1,'asd',67,100],f)
    pickle.dump([2,'asfawf',76,100],f)
    pickle.dump([3,'awdawd',65,100],f)
    pickle.dump([4,'awdawd',90,100],f)
def count_short_attendance():
    with open('ATTENDANCE.dat','rb') as f:
        x=[]
        l=[]
        n=0
        while True:
            try:
                x.append(pickle.load(f))
            except EOFError:
                break
        for i in x:
            if i[2]/i[3]<0.75:
                l.append(i)
                n+=1
        if len(l)==0:
            print('There are no students with less than 75% attendance.')
        else:
            print('Students with less than 75% attendance:')
            for j in l:
                print('Admission number :',j[0])
                print('Name :',j[1])
                print('Attendance :',j[2])
                print('Working days :',j[3])
            print('Number of students with less than 75% attendance :',n)
count_short_attendance()
