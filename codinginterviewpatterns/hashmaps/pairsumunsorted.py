from typing import List

nums = [-1, 3, 4, 2]

def pair_sum_unsorted_two_pass(nums: List, target: int ) -> List[int]:
    num_map = {}
    
    # First pass: populate the hash map with each number and its index
    for i, num in enumerate(nums):
        num_map[num] = i

    # Second pass: check for each number's complement in the hash map

    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map and num_map[complement] != i:
            return [i, num_map[complement]]
    return []
    
pair_sum_unsorted_two_pass(nums, 1)









