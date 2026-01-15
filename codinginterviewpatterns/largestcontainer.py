from typing import List

def largest_container(heights: List[int]) -> int:
    max_water = 0
    left, right = 0, len(heights) - 1

    while (left < right):
        water = min(heights[left], heights[right] * (right - left))
        max_water = max(max_water, water)

        if (heights[left] > heights[right]):
            right -= 1
        elif (heights[left] < heights[right]):
            left += 1
        else:
            left += 1
            right -= 1
    return max_water


def largest_container1(heights: List[int]) -> int:

    max_water = 0 
    left, right = 0, len(heights) - 1
    
    #max_water = (min(heights[left], heights[right]) * (right-left))
    #print(min(heights[left], heights[right]))

    #it won't print the above codes because heights[-1] doesn't exist
    while (right > left):
        water = (min(heights[left], heights[right]) * (right-left))
        max_water = max(water, max_water)
        
        if (heights[right] > heights[left]):
            left += 1
        elif (heights[right] < heights[left]):
            right -= 1
        else:
            left += 1
            right -=1
    return max_water


        




heights = [2, 7, 8, 3, 7, 6]

x = 0

x = largest_container1(heights)

test = [3, 2, 1]

y = largest_container1(test)
print(y)