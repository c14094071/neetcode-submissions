# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        total = 0
        curr = head
        while(curr!= None):
            curr = curr.next
            total +=1
        order = total - n +1
        if(order == 0): return head.next
        dummy = ListNode(None,head)
        dummy2 = ListNode(None,dummy)
        count = 1
        while(dummy.next!=None):
            if(count==order):
                dummy.next = dummy.next.next
                break
            dummy = dummy.next
            count +=1
        return dummy2.next.next
