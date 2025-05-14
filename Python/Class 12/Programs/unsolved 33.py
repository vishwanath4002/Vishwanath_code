#write a method in python to write multiple lines of text contents into a text file "mylife.txt".
with open('mylife.txt','w') as f:
    while True:
        f.write(input('Input the line : ')+'\n')
        c=input('Do you want to continue? (yes/no) : ')
        if c=='no':
            break
        elif c=='yes':
            continue
        else:
            print('Invalid entry. Please try again.')
with open('mylife.txt','r') as f:
    print(f.read())
