# The following program lets the user type in a pet name and then check to see
# whether the name is in a list of pets.

My_Pets = ['Zhopie', 'Pooka', 'Fat-tail', 'Linda']

Name = input()
if Name not in My_Pets:
    print('I do not have a pet named ' + Name)
else:
    print(Name + ' is my pet')
