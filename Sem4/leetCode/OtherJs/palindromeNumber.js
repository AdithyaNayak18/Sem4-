/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    x=x.toString();
    let len = x.length - 1;
    let i = 0;
    while (i <= len) {   
        if (x[i] !== x[len]) return false;
        i++;
        len--;
    }
    return true;
};
