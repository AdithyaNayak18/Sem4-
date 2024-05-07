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
 */
var doubleIt = function(head) {
    let temp = head;
    let count = 0;
    let array = [];
    let num = 0;
    
    while (temp !== null) {
        num *= 10;
        num += temp.val;
        temp = temp.next;
    }
    num *= 2;
    
    while (num % 10 !== 0) {
        array.unshift(num % 10);
        num = Math.floor(num / 10);
    }
    
    let newHead = null; 
    let tail = null; 

    // Convert the array back to a linked list
    for (let value of array) {
        let current = new ListNode(value); 
        if (newHead) {
            tail.next = current; 
            tail = tail.next; 
        } else {
            tail = newHead = current;
        }
    }

    return newHead; 
};
