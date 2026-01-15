#first step I mapped out now do i need any libraries?
import array
import numpy as np
import string

print("running the right file")

def main():

        print("hello")

        scores = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10]
        alphabet = list(string.ascii_uppercase)

        letters_to_score = {letter: scores[i] for i, letter in enumerate(string.ascii_uppercase)}

        

        player1 = input("Player1:")
        player2 = input("Player2:")

        x = len(player1)
        

        word1 = player1.upper()
        word2 = player2.upper()

        total1 = 0
        total2 = 0
        for c in word1:
                if c in letters_to_score:
                    total1 += letters_to_score[c]

        

        for d in word2:
                if d in letters_to_score:
                    total2 += letters_to_score[d]

        if total1 > total2:
              print("Player 1 wins!")

        if total2 > total1:
              print("Player 2 wins!")
                    

          

        # okay i got the WORD, now how do i transfer the word or map the word to the dictionary
        # do i get the string length first

        # i need to match the char in player1 input to the dictionary, get the 2nd value, sum it up



        #enumerate turns the key and value into pairs



        #for i in range(len(scores)):

            # print(scores[i])




main()

    
