from typing import List

nums = [-5, -2, 3, 4, 6]

target = 7

nums2 = [0, -1, 2, -3 ,1]

target1 = 0

start = 0


def tripletsum(nums2 = List[int]) -> List[int]:

    triplets = []
    #there was a command to sort the list i forgot what it was though

    #so we can break down this problem into a smaller problem if we understand that we can
    #find the value of a or -a, and then pairsum b and c to it and it will equal to zero

    # so first we have to sort the code assume its sorted

    # we have to check if the lowest value is above 0 if it is then its not possible to equal 0
    nums2.sort()
    print(nums2)


    for i in range(len(nums)):
        left = i+1
        right = len(nums) - 1
        if nums2[i] > 0:
            break

        if nums2[i] == nums2[i-1]:
            continue
        
        pairs = pairsum(nums2, i+1, -nums[i])
        

        #so there could be multiple pairs right and you want to output all of them

        for pair in pairs:
            triplets.append[nums[i] + pairs]

    return triplets


    #so we have to loop and start at the first value, and then pairsum the rest to see if they add to it

    #so should we use a while loop or for loop

        
            

            

def pairsum(nums: List[int], start: int, target: int) -> List[int]:
    pairs = []
    left, right = start, (len(nums) - 1)



    while sum != target:
        sum = nums[left] + nums[right]
        
        if sum == target:
            pairs.append[nums[left], nums[right]]
        if sum < target:
            left += 1

        elif sum > target:
            right -= 1
    
        else:
            return pairs

x = []

x = pairsum(nums, target)

print(x)

x = tripletsum(nums2, 0)
print(x)

#the key to this problem is recognizing that the input is sorted so we can use two pointer 
#for faster time complexity.
    
