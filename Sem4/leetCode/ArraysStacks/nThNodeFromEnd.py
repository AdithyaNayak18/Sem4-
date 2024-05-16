class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return head

        count = 0
        temp = head
        while temp:
            count += 1
            temp = temp.next

        x = 0
        temp = head
        prev = temp

        if n == count:
            return head.next

        while x != count - n:
            prev = temp
            temp = temp.next
            x += 1

        prev.next = temp.next
        return head
