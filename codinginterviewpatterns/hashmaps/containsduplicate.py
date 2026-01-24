from typing import List


numsy = [1, 2, 3, 1]
nums2 = [1, 2, 3, 4]
nums3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]

def containsDuplicate( nums: List[int]) -> bool:
    seen = set()
    for x in range(len(nums)):
        number = nums[x]

        if number in seen:
            return True
    
        seen.add(number)
    return False


print(containsDuplicate(numsy))
print(containsDuplicate(nums2))
print(containsDuplicate(nums3))

