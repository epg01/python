#This program stores the names of a person's cates.

Cat_Names = []    #  An empty list was created.

while True:
    print('Enter the name of the ' + str(len(Cat_Names) + 1) + ' (Or enter nothing to stop.):')
    Name = input()
    if Name == '':
        break
    else:
        Cat_Names = Cat_Names + [Name]   # or written in another way:
                                         # Cat_Names += [Name]
print('The cate names are:')
for Name in Cat_Names:
    print('  ' + Name)
