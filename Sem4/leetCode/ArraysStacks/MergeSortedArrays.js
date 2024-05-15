/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) 
{
    let temp1=list1;
    let temp2=list2;
    var head=new ListNode();
    var tail=head;
    var temp=null;
    while((temp1)&&(temp2))
    {
        if(temp1.val<=temp2.val) {temp= temp1; temp1=temp1.next;}
        else {temp=temp2; temp2=temp2.next;}
        tail.next=temp;
        tail=tail.next;    
    }
    if(temp1) {tail.next=temp1;temp1=temp1.next;}
    if(temp2) {tail.next=temp2;temp2=temp2.next;}
    return head.next;
}
