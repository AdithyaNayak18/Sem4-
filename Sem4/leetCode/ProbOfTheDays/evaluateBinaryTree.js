/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var evaluateTree = function(root) {
    if(!root) return null;
    if(root.left === null && root.right=== null) return root.val;
    root.left=evaluateTree(root.left);
    root.right=evaluateTree(root.right);
    let var1=((root.left===1)? true : false);
    let var2=((root.right===1)? true : false);
    if(root.val===2 && (var1 || var2)) return 1;
    else if(root.val===3 && (var1 && var2)) return 1;
    else return 0;
    
};
