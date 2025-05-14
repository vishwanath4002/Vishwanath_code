def wordDetails():
    with open('string.txt','r') as f:
        x=f.read()
        x=x.split()
        print('Total number of words is %s.'%(len(x)))
        for i in x:
            print()
            c=0
            for j in i:
                if j.lower() in 'aeiou':
                    c+=1
            print('%s , number of vowels : %s'%(i,c))

def countAWord():
    with open('string.txt','r') as f:
        print('Count of "the" in the text file is : %s'%(f.read().lower().count('the')))

with open('string.txt','w') as f:
    f.write('Hello world the ')
wordDetails()
countAWord()
