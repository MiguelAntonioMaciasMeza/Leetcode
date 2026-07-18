/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    var sortedArray = [];
    var size = arr.length;

    for(let i = 0; i < size; i++){
        var smallestIndex = findSmallest(arr);
        var smallest = arr.splice(smallestIndex, 1);
        sortedArray.push(smallest[0]);
    }

    return sortedArray;
};

function findSmallest(array){
    var smallest = array[0];
    var index = 0;
    for (let i = 0; i < array.length; i++){
       if(smallest > array[i]){
        smallest = array[i];
        index = i;
       }
    }
   
    return index
}