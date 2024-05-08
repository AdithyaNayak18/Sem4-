/*
given a score array of integers say [4, 2,10, 7, 11] Ensuring no numbers r repeated, an array with ranks should be returned with Gold, Silver 
and Bronze for 1,2,3 and "4th", "5th".... for the rest!

*/

var findRelativeRanks = function(score) {
    let dup = score.slice();
    var length = score.length;
    var rank = [];
    dup.sort((a, b) => b - a);

    for (let i = 0; i < length; i++) {
        let index = score.indexOf(dup[i]); 
        var medal;

        switch (i) {
            case 0:
                medal = "Gold Medal";
                break;
            case 1:
                medal = "Silver Medal";
                break;
            case 2:
                medal = "Bronze Medal";
                break;
            default:
                medal = (i + 1).toString();
        }

        rank[index] = medal;
    }

    return rank;
};
