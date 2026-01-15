from typing import List


nums = [-5, -2, 3, 4, 6]

test = [2]

test1 = [-5, -2, 3, 3, 4, 6]

target = 7 

def pair_sum_sorted(nums: List[int], target: int)  -> List[int]:

    n = len(nums)
    
    for i in range(n):
        for j in range(i+1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
            
    
    return[]

x = []

x = pair_sum_sorted(nums, target)

# print(x)

def pair_sum_sorted_quick(nums: List[int], target: int) -> List[int]:

    n = len(nums)
    left, right = 0, (n-1)

   

    while right > left:
        sum = nums[left] + nums[right]
        print(sum)
        if sum < target:
            left += 1
        elif sum > target:
            right -= 1
        else:
            return[left, right]
    

    return []    
    
    #nums[left] + nums[right] < target:
    # nums[left] = nums[left+1]

    while nums[left] + nums[right] > target:
        nums[right] = nums[right+1]
    else:
        return nums[left, right]
    
x = pair_sum_sorted_quick(test1, target)

print(x)

#different ways to test it

# testing an empty array
# testing values outside of the array?
# testing negative values?
# testing edge cases
# testing an array with just one element
