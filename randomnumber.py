#okay so we are building a random number generator and guessor game
#user has to guess the number until they get it correct

import random

#generates a random number between 1 and 100
randomNumber = random.randrange(1, 100)

#prints random number 
print(randomNumber)

#prompts user for input 
#sets guess count as int variable
# guess = int(input("Guess the number: "))
guesscount = 0

lowerLimit = 1
upperLimit = 100

aiguess = int((lowerLimit + upperLimit) / 2)
print("Ai guess", aiguess)

# Start of loop that prompts user until correct guess is made
while aiguess != randomNumber: 
    #adds to the counter everytime user guesses wrong
    guesscount += 1

    if aiguess < randomNumber:
        print("A little higher\n")
        lowerLimit = aiguess
        aiguess = int((lowerLimit + upperLimit) / 2)
        print("Ai guess", aiguess)
        # guess = int(input("Guess the number: "))
        

    elif aiguess > randomNumber:
        print("A little lower\n")
        upperLimit = aiguess
        aiguess = int((lowerLimit + upperLimit) / 2)
        print("Ai guess", aiguess)
        # guess = int(input("Guess the number: "))
else:
    print("You got it!")
    print("The number of guesses you took was:", guesscount)



