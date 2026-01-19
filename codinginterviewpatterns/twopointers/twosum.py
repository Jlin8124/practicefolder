
from typing import List

class Solution:
    def twosum(self, nums: List[int], start: int, target:int) -> List[int]:
        pairs=[]
        left = start
        right = len(nums) - 1
        
        while ( right > left):
            if (nums[left] + nums[right] > target):
                right -= 1
            elif (nums[left] + nums[right] < target):
                left += 1
            
            else:    
                pairs.append(nums[left], nums[right])
                left += 1
                right -= 1
        return pairs
    
    def threesum(self, nums: List[int], target:int) -> List[int]:

        nums.sort()
        triplets=[]

        solver=Solution()
        

        for i in range(len(nums)):


            if nums[0] > 1:
                break

            if i > 0 and nums[1] == nums[i-1]:
                continue
                
            pairs = solver.twosum(nums, i+1, -nums[i])

            for pair in pairs:
                triplets.append[nums[i], pair]
                
            return triplets

                
nums = [1, 2, 3, 4, 9]
print(len(nums))

solver = Solution()

result = solver.twosum(nums, 0, 12)

print(result)
nums2 = [-4, -5, 3, 4, 9]
result2 = solver.threesum(nums2, 0)
print(result2)







