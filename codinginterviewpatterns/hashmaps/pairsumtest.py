from typing import List

nums = [-1, 3, 4, 2]

def pair_sum_unsorted(nums: List[int], target: int) -> List[int]:

    num_map = {}

    for i, x in enumerate(nums):
        if target - x in num_map:
            return [num_map[target - x], i]

        num_map[x] = i
    return []

result = pair_sum_unsorted(nums, 3)

print(result)

for res in result:
    print(nums[res])