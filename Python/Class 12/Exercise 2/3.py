def checknumber(ph_num):
    c=0
    for i in range(len(ph_num)):
        if ph_num[i].isdigit():
            if i==3 or i==7:
                return False
            else:
                c+=1  
        elif ph_num[i]=='-':
            if i==3 or i==7:
                c+=1
            else:
                return False
        else:
            return False
    if c==12:
        return True
    else:
        return False
        
