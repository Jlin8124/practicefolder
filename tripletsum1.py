from typing import List

nums = [0, 0,  -1, 2, -3, 1]

target = 0 

def tripletsum(nums: List[int], target = int) -> List[int]:

    triplets = []
    nums.sort()

    for i in range(len(nums)):

        if nums[i] > 0:
            break

        # we have to take i and then iteratee over the remaining to see if there are any duplicates for a and b, then c is forced
        
        if i > 0 and nums[i] == nums[i-1]:
            continue
        # so i in range is the index positions 0, 1, 2, 3, 4
        # we can't compare index 0 and index -1 because it doesn't exist so i has to be > 0 for this work
        # if the value of i and i-1 are the same then we don't want to get duplicates so we stop this iteration 
        # and go to the next iteratio

        pairs = twosum(nums, i+1, -nums[i])

        #defining variable pairs calling two sum which returns the index positions of two values that = the target
        #the target in this case would be -nums[i]



        for pair in pairs:
                triplets.append([nums[i]] + pair)


    return triplets

def twosum(nums: List[int], start = int, target = int) -> List[int]:

    pairs = []
    n = len(nums)
    left, right = start, n-1
    # we have to point to the start and the end

    while right > left:

        sum = nums[left] + nums[right]

        if sum == target:
            pairs.append([nums[left], nums[right]])
            left +=1

            while right > left and nums[left] == nums[left-1]:
                left += 1

        elif sum < target:
            left += 1

        else:
            right-= 1
        
        
    return pairs

x = []

x = tripletsum(nums, target)

print(x)


