#This program that keep asking you to type, litarally, "your name"

try:
    Name = input()
except EOFError:
    Name = ''

while Name != 'your name':
    print('Try again, write your name')
    try:
        Name = input()
    except EOFError:
        Name = ''
print('Well done')
