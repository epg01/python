try:
    print('Enter Emmanuel name')
    Name = input()
except EOFError:
    print("Enter Dato valid.")
    Name = ''
if Name == 'Emmanuel':
    print('Hello, Emmanuel Welcome!')
else:
    print('your are not Emmanuel')
