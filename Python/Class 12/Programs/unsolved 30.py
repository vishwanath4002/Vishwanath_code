#Write a python program to display the size of a file after removing EOL characters, leading and trailing white spaces and blank lines.
with open('sample.txt','r') as f:
    s=''
    for i in f.readlines():
        s+=i.strip().replace(' ','')
    print(len(s))

