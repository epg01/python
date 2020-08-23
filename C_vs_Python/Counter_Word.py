# This program counts the occurences of each word.

Message = ["MI", "primer" , "programa" , "que", "cuanta", "ocurrencias",  "de", "cada", "palabra", "de" , "una",  "manera", "no",  "tan", "general", "que", 'que']
Counter = {}

for String in Message:
    Counter.setdefault(String, 0)
    Counter[String] += 1;
for key, Value in Counter.items():
    print('Key ' + key + ' value = ' + str(Value))
