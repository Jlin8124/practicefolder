
def print_stuff(comment):
    print("######")
    print(comment)
    print("######")

def print_stuff1():
    print("######")
    print("hello")
    print("######")
   
print_stuff("YELLO")

myVar = "Wassup"

print_stuff(myVar)
print(type(print_stuff))

something = print_stuff1()


print(type(something))

def return_one_hundred():
    return 100

something = return_one_hundred()
print(something)
print(type(something))


#so lets say you have a list 
#could make a list variable
def average(numbers):
    return sum(numbers) / len(numbers)

average1 = average([2, 3, 4 , 5, 6 ])
print(average1)

print("Average is:", sum([2 , 3, 4, 5, 6]) / len([2, 3, 4, 5, 6]))

print(divmod(5,2))

def outer_function(what):
    def inner_function():
        print("I like", what)
    inner_function()
outer_function("python")

def countdown(n):

    print(n)

    if n == 0: #this is our base case, when n is equal to 0
        return
    else:
        countdown(n-1)
        #so we are calling the function in itself again WOO

countdown(10)


def factorial(number):
    if not isinstance(number, int):
        raise TypeError("Sorry. number must be an integer.")
    if number < 0:
        raise ValueError("Sorry number must be above 0")



