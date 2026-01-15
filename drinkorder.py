import sys

drinkDetails = ''

choice = input("Water, Coffee, or Tea? ")

if choice == "Water" or "water":
    print("You chose Water!")
    temperature = input("Hot or Cold? ")
    drinkDetails = choice

    if temperature == "Hot":
        sys.exit(0)
    elif temperature == "Cold" or "cold":
        ice = input("Ice or No Nice\n")
        

elif choice == "Coffee" or "coffee":
    print("You chose coffee!")
    drinkDetails = choice
elif choice == "Tea" or "tea":
    print("You chose tea!")
    drinkDetails = choice
else:
    print("Sorry we don't have that drink available for you")

print("Your drink was:", drinkDetails)

temp = 104

if temp > 80:
    print("its hot!")
elif temp > 90:
    print("its blazing")


jasonLin = ['Jason', 25, 'Lin', 1994]

print(jasonLin[2])

print(jasonLin[-3])

person = {
    "Name": 'Jason',
    'Age': 25,
    'City': 'Mississauga'
}

print ("Jason" in jasonLin)
