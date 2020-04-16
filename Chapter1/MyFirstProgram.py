# The second line is a comment, the comments star with a mark (#)
# This program says hello and asks for my name

print('Hello word')               # In this line we call the print function with the argument enclosed in single quotes
print('What is your name?')

myName = input()                  # A variable was declared and defined, of type string: I know this because an input()
                                  # function is called that receives information from the keyboard and any information
                                  # copied to it becomes a string (which should happen)

print('It is good for meet you, ' + myName)  # As the variable myName is of type string, then when using the operator
                                             # + (the becomes the string concatenation operator), that is, with this
                                             # we concatenate the two strings that appear in the print() function
print('The length of your name is:')
print(len(myName))                           # The len() function was called which counts the visible strings of the
                                             # varible myName
print('What is your age?')
myAge = input()

# In the latter we do a cast, the int() function converts it to an integer (but we must be careful), and the string() 
# function casts in into a string

print('You will be ' +str(int(myAge) + 1) + ' in a year.')
