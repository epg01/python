# This program applies the concept of a dictionary list.

# we create a data type (dictionariy)

birthdays = {'Alice': 'Apri 1', 'Bob': 'May'}

while True:
    print('Enter a name: (blank to quit)')
    Name = input()
    if Name == '':
        break;
    if Name in birthdays:
        print(birthdays[Name] + ' is the birthdays of ' + Name)
    else:
        print('I do not have birthdays information for ' + Name)
        print('What is their birthday?')
        bday = input()
        birthdays[Name] = bday
        print('Birthday database update.')
