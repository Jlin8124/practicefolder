# Removing the kth Last Node from a Linked List
#Find the K node
#removing K node
#connecting node previous to k to node after K

class ListNode:
    def _init__(self, val=0, next=None):
        self.val = val
        self.next = next

def remove_kth_last_node(head: ListNode, k: int) -> ListNode:
    dummy = ListNode(-1)
    dummy.next=head

    trailer = leader = dummy
    for _ in range(k):
        leader=leader.next

        if not leader:
            return head

    while leader:
        leader = leader.next
        trailer = trailer.next
    
    trailer.next = trailer.next.next
    return dummy.next