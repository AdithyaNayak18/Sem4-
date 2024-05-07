/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.next = (next === undefined ? null : next);
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 given a List say [4, 2, 2] , we are expected to return a linked list with [8, 4, 4] or incase of [7,2,5] = [1,6,5,0]

 */
var doubleIt = function(head) {
    let temp=head;
    let array=[];
    var carry=0;
    while(temp)
    {
    array.push(temp.val);
    temp=temp.next;
    }

    for(let i=array.length-1;i>=0;i--)
    {
        carry+= 2*array[i];
        array[i]=carry%10;
        carry=Math.trunc(carry/10);
    }
    if(carry) array.unshift(carry);

    let newHead=null;
    let tail=null;
    for(let val of array)
    {
        temp = new ListNode(val);
        if(newHead)
        {
            tail.next=temp;
            tail=tail.next;
        }
        else
        newHead=tail=temp;
    }
    return newHead;
};
