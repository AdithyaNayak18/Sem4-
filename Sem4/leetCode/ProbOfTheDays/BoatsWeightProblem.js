/**
Given weight of people ex: [4,2,1,5,2], we must board them on a boat such that it doesnt exceed Limit Weight
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */

var numRescueBoats = function(people, limit) {
    people.sort((a,b)=>a-b);
    var boats=0;
    let i=0;j=people.length-1;
    while(i<=j)
    {
        if(i==j)
            return ++boats;
        if(people[i]+people[j]>limit)
        j--;
        else
           {
            i++;
            j--;
           }
        boats++;

    }
    return boats;
};
