from typing import List


nums = [5, -2, 3, 4, 6]

arget = 7

#Brute force approach create an outer loop for the first number of the array, and then an inner loop that transverses the rest of the array

def pair_sum_sorted_brute_force(nums: List[int], target: int) -> List[int]:

    n = len(nums)
    for i in range(n):
        
        for j in range(i + 1, n):
            
            if nums[i] + nums[j] == target:
                return [i, j]
            
   
    return[] 


        #for j in range(n-1):
           # if nums[i] + nums[j]

        # we need to start from the 2nd element of the array. key word 2nd element or the 1 position 
        # do we need to +1 or -1 from something
        # we have the inner loop starting at J 
answer = []

answer = pair_sum_sorted_brute_force(nums, 7)

print(answer)

def pair_inward_transverseral(nums: List[int], target: int) -> List[int]:

    left, right = 0, len(nums) - 1
    #we have to create a two pointer solution idk what the word is where the the first opinter starts at the begnning
    # 2nd pointer starts at the right we increment left to right
    
    while left < right:

        sum = nums[left] + nums[right]

        if sum < target:
            left += 1
        elif sum > target:
            right += 1
        else:
            return [left, right]
        
    return []


    #for i in range(n):
        #if nums[i] + nums[n] < 7:
            #continue

        #elif nums[i] + nums[n] > 7:
            #n = n-1


    



        






        #for j in range(i+1, n):
            if nums[i] + num[j]
            






