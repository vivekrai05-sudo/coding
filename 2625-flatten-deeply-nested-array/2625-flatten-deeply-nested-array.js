/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let ans=[];
    function helper(arr,n){
        for(let item of arr){
            if(Array.isArray(item) && n>0){
                helper(item,n-1);
            }
            else{
                ans.push(item);
            }
        }
    }
    helper(arr,n);
    return ans;
};