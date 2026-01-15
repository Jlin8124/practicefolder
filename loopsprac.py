#okay we learned about iter and next how do I implement it
#do i create a list first 


list = ['a', 'b', 'c', 'd']

it = iter(list)

print(next(it))
print(next(it))
print(next(it))
print(next(it))
x = 0

while x != 5:
    
    userinput = int(input("What is the value of x?"))
    x = userinput

print("finished")


myNumber = 5

while myNumber != -1 :

    print(myNumber)
    myNumber -= 1

else:
    print("Blast off!")

#break immediately ends the loop 
#continue which ends the current iteration (or the current repeating or a process that could generate(unboundless)) sequence of outcomes

friendsList = ['Desmond', 'Kevin', 'Chris']

for w in friendsList:
    print("Happy New Year:", w)

#how do i get the count now

x = len(friendsList)

#for i in x:
    #print(friendsList[i])


for x in range(3,5):
    print(x)


smallestValue = None

print('Before:', smallestValue)
for itervar in [3, 41, 12, 9, 74, 15]:
    if smallestValue is None or itervar < smallestValue:
        smallestValue = itervar
    print("smallest value is:", smallestValue)


numbertoFind = 12

for itervar in [3, 41, 21, 9, 74, 15]:
    if itervar == numbertoFind:
        print("number found")
        break
else:
    print("number not found")





