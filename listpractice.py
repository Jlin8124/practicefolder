firstList = ['dog', 'cat', 'fish', 'bear', 'bird', 'owl']
#print(firstList)
firstList.sort()

#print(firstList)

removedanimal = firstList.pop(3)

#print(removedanimal)

listElement = iter(firstList)

print(next(listElement))

#i forgot about the sort

#you could have a next element what about a for loop

for list in firstList:
    print(list)

secondList = ['dog', 'cat', 'fish', 'bear', 'bird', 'owl']
myElement = "gelato"

secondList = secondList + [myElement]
print(secondList)


