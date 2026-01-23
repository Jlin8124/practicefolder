s = "PythonProgramming"

print (s[6 : 17])

print (s[3 : 9])

print (s[-3:])

print (s[::2])

x = len(s)
print(x)

#0-16
for i in range(len(s)):
    print(s[len(s) - 1 - i], end ="")

print(" ")