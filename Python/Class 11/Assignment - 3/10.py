#WAP read email id to ensure @gmail.com
s=input('Enter the email id : ')
if s.endswith('@gmail.com'):
    print('Valid')
else:
    print('Invalid')
