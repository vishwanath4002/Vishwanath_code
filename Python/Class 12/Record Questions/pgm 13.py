def moveCharacters():
    with open('sentence.txt','r') as f:
        with open('lower.txt','w') as l:
            with open('upper.txt','w') as u:
                with open('digit.txt','w') as d:
                    for i in f.read():
                        if i.isdigit():
                            d.write(i)
                        elif i.isalpha():
                            if i.islower():
                                l.write(i)
                            elif i.isupper():
                                u.write(i)

def palindrome():
    with open('sentence.txt','r') as f:
        with open('palindrome.txt','w') as p:
            for i in f.read().split():
                if i==i[::-1]:
                    p.write(i+' ')

with open('sentence.txt','w') as f:
    f.write('malayalam racecar python 123 ComputeR SCIEnce')
moveCharacters()
palindrome()
with open('upper.txt','r') as u:
    with open('digit.txt','r') as d:
        with open('palindrome.txt','r') as p:
            print(u.read())
            print(d.read())
            print(p.read())
