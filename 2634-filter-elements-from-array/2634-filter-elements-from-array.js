/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans=[];
    arr.forEach((item,i)=>{
        if(fn(item,i)){
            ans.push(item);
        }
    });
    return ans;
};