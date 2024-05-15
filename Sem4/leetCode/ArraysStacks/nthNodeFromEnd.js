/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    if(head===null)
        return head;
    let count=0;
    let temp=head;
    while(temp)
    {
        temp=temp.next;
        count++;
    }
    let x=0;
    temp=head;
    prev=temp;
    if(n===count) return head.next;
    let rem=count-n
    while(x!==rem)
    {
        prev=temp;
        temp=temp.next;
        x++;
    }
    prev.next=temp.next;
    return head;
};
