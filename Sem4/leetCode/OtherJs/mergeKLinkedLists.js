/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var merge2Lists=function(l1,l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1.val>l2.val){
        l2.next=merge2Lists(l1,l2.next);
        return l2;
    }
    else{
        l1.next=merge2Lists(l1.next,l2);
        return l1;
    }
}
var mergeKLists=function(lists){
    let ans=null;
    for(let list of lists) ans=merge2Lists(ans,list);
    return ans;
}
