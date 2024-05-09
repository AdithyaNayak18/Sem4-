/**
 * @param {Function} fn
 * @return {Function}

Given an array of functions, use a count variable to determine the numbeer of different function calls, count++ only if Function is new
If input is proper, return fn(input), else return count if i/p is []
 */
function memoize(fn) {
    var memo = {}; // Store memoized results
    let count = 0; // Count unique function calls

    return function(...args) {
        var key = args.join('-'); // Generate a unique key for the arguments

        if (!(key in memo)) { // Check if the result is not memoized
            count++; // Increment count for unique function calls
            memo[key] = fn(...args); // Memoize the result for the arguments
        }

        if (!args.length) // Return count if function is called without arguments
            return count;

        return memo[key]; // Return the memoized result
    };
}



/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
