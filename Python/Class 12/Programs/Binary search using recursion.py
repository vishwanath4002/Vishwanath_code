def bin_search(t,start,end,s):
    if start<end:
        m=(start+end)//2
        if t[m]==s:
            return m
        elif s>t[m]:
            return bin_search(t,m+1,end,s)
        elif s<t[m]:
            return bin_search(t,start,m,s)
    else:
        return -1

x=eval(input('Enter the list : '))
y=int(input('Enter the number : '))
print(bin_search(x,0,len(x),y))
