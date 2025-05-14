def linedetails():
    x=1
    with open('line.txt','r') as f:
        for j in f.readlines():
            print('line',x)
            l=0
            v=0
            d=0
            s=0
            sp=0
            for i in j:
                if i.isalpha():
                    l+=1
                    if i.lower() in 'aeiou':
                        v+=1
                elif i.isdigit():
                    d+=1
                elif i.isspace():
                    s+=1
                else:
                    sp+=1
            print('letters : %s\nvowels : %s\ndigits : %s\nspaces : %s\nspecial characeters : %s\n'%(l,v,d,s,sp))
            x+=1
with open('line.txt','w') as f:
    f.write('awdAW12@4f assfaj\nawkfjb awda  s@21\n32@@# @ja skjbwf')
linedetails()
