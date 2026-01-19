
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next 


def linked_list_reversal(head: ListNode) -> ListNode:
    curr_node, prev_node = head, None

    while curr_node:
        next_node = curr_node.next
        curr_node.next = prev_node
        prev_node = curr_node
        curr_node=next_node
    return prev_node

def linked_list_reversal_recursive(head: ListNode) -> ListNode:
    if (not head) or not(head.next):
        return head
    new_head = linked_list_reversal_recursive(head.next)
    
    head.next.next = head
    head.next = None
    return new_head





