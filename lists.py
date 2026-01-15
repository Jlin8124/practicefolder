#Lesson 2.1 - 6 Lists

# lists are mutable [] - use linear search much slower
# sets are not mutable {} - use hash table 
# Tuples are completely unchangeable
# mutable means you can add and remove, but you cannot change or replace

paragraph = "Good, Better, Best. Never let it rest. Until your good is better and your better is best"


words = paragraph.split()
print(words)
word_count = {}

for w in words:
    w = w.lower()
    if w in word_count:
        word_count[w] += 1 
    else:
        word_count[w] = 1 

print(word_count)

