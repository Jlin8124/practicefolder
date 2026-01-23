from typing import List

nums = [-1, 3, 4, 2]

def pair_sum_unsorted(nums: List[int], target: int) -> List[int]:

    num_map = {}

    for i, num in enumerate(nums):
        if target - num in num_map:
            return [num_map[target - num], i]
        num_map[num] = i
    return []

result = {}
result = print(pair_sum_unsorted(nums, 3))
result = (pair_sum_unsorted(nums, 3))

for res in result:
    print(nums[res])

#now how do we print the actual element values

