from typing import List

nums = [-5, -2, 3, 4, 6]

target = 7

nums2 = [0, -1, 2, -3 ,1]

target1 = 0

start = 0

sum = 0

def tripletsum(nums2: List[int], target:int) -> List[int]:

    triplets = []
    nums2.sort()

    for i in range(len(nums2)):
        if nums2[i] > 0:
            break

        elif nums2[i] == nums2[i-1]:
            continue
        
        pairs = pairsum(nums2, i+1, -nums2[i])
        for pair in pairs:
            triplets.append([nums2[i], pair])
    return triplets

def pairsum(nums: List[int], start:int, target: int) -> List[int]:
    
    pairs = []

    left, right = start, len(nums) - 1
    sum = 0
    while sum != target:
        sum = nums[left] + nums[right]

        if sum == target:
            pairs.append([nums[left], nums[right]])

        if sum < target:
            left += 1
        else:
            right -= 1
    return pairs

x = []



print(x)

x = tripletsum(nums2, target1)

print(x)


