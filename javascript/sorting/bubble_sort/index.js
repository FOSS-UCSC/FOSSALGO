// swaping function - private
// x,y: indexes; lst: array
// time - bestcase case - O(1)
// time - average case - O(1)
// time - worst case - O(1)
var swap = (x, y, lst) => {
  let tmp = lst[x];
  lst[x] = lst[y];
  lst[y] = tmp;
}

// increasing order - basic algorithm
// time - bestcase case - O(n)
// time - average case - O(n^2)
// time - worst case - O(n^2)
module.exports.basic = (lst) => {
  for(i=lst.length-1;i>0;i--) {
    for(j=0;j<i;j++) {
      if(lst[j]>lst[j+1]) {
        swap(j,j+1,lst);
      }
    }
  }
  return lst;
}

// decreasing order - basic algorithm
// time - bestcase case - O(n)
// time - average case - O(n^2)
// time - worst case - O(n^2)
module.exports.basic_reversed = (lst) => {
  for(i=lst.length-1;i>0;i--) {
    for(j=0;j<i;j++) {
      if(lst[j]<lst[j+1]) {
        swap(j,j+1,lst);
      }
    }
  }
  return lst;
}