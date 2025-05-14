#Write a function st_details(x,y) to write n student details
#(roll number - Name) in a text file x opened in y mode.

print('Mode entered should be either w or a.')
def st_details(x,y):
    with open(x+'.txt',y) as x:
        n=int(input('Enter the number of students : '))
        for i in range(n):
            x.writelines([input('Enter the roll number : '),' - ',input('Enter the name : '),'\n'])
st_details('z','w')
