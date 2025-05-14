#tuple containing (a,bb,ccc,ddd,,,)
t=()
for i in range(97,123):
    t+=chr(i)*(i-96),
print(t)
