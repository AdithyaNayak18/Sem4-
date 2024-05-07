//Given 2 linked lists say [2,5,6] and [6,5,2] we add 256+652 and give the output 1008 as [1,0,0,8] as a linked list!

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var array=[];
    let sum=0;
    let carry=0;
    node1=l1;
    node2=l2;
    while(node1 !== null || node2 !== null)
    {
      sum = (node1 !== null ? node1.val : 0) + (node2 !== null ? node2.val : 0) + carry;
        carry = Math.floor(sum / 10);
        array.push(sum % 10);

         if (node1 !== null) node1 = node1.next;
        if (node2 !== null) node2 = node2.next;
    }
    let newHead=null;
    let tail=null;

    for(let val of array)
    {
        let temp= new ListNode(val);
        if(newHead)
        {
            tail.next=temp;
            tail=tail.next;
        }
        else
        tail=newHead=temp;
    }
    return newHead;
    
};
