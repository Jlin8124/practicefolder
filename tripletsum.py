from typing import List


nums = [0, -1, 2, -3 ,1]

target = 0

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
    


def triplet_sum(nums: List[int], target: int) -> List [int]:

    n = len(nums)

    # brute force solution 3 loops

    for i in range(n):
        for j in range(i+1, n):
            for h in range(i+2, n):
                if nums[i] + nums[j] + nums[h] == target:
                    print(nums[i])
                    print(nums[j])
                    print(nums[h])
                    print(i)
                    print(j)
                    print(h)
                    return [i, j, h]
    
    return[]

x = []

x = triplet_sum(nums, 0)

print(x)

practicelist = [2, 2, 4, 5, 6, 4, 5]


# practicelist = set(practicelist)

#you can turn an array or a list of values or collection values into a set with no duplciates through the set("name of variable")

print(practicelist)



def triplet_sum(practicelist = List[int], target = int) -> List[int]:

    triplets =[]
    practicelist.sort()

    for i in range(len(practicelist)):
        
        # if the list is sorted from lowest to highest, if the lowest number is greater than 0
        # the sum cannot be = to 0
        if nums[i] > 0:
            break
        # -(a+b) = c

        if i > 0 and nums[i] == nums[i-1]:
            continue

        pairs = pair_sum_sorted_quick(practicelist, i + 1, -nums[i])
        for pair in pairs:
            triplets.append([practicelist[i]] + pair)
    return triplets

