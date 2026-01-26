from typing import List

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def linked_list_intersection(head_A: ListNode, head_B: ListNode) -> ListNode:
    
    ptr_a = head_A
    ptr_b = head_B

    while (ptr_a != ptr_b):

        ptr_a = ptr_a.next if ptr_a else head_B
        ptr_b = ptr_b.next if ptr_b else head_A

    return ptr_a




