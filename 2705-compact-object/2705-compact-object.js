/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(Array.isArray(obj)){
        return obj
        .filter(Boolean)
        .map(compactObject);
    }
    else if(obj!==null && typeof obj=="object"){
        const result={};
        for(let key in obj){
            const value=compactObject(obj[key]);
            if(Boolean(value)){
                result[key]=value;
            }
        }
        return result;
    }
    return obj;
};