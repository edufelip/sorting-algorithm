const merge = function (list, beg, middle, end) {
  const leftList = list.slice(beg, middle);
  const rightList = list.slice(middle, end);
  let i = 0;
  let j = 0;
  for (let k = beg; k < end; k++) {
    if (i >= leftList.length) {
      list[k] = rightList[j];
      j++;
    } else if (j >= rightList.length) {
      list[k] = leftList[i];
      i++;
    } else if (leftList[i] < rightList[j]) {
      list[k] = leftList[i];
      i++;
    } else {
      list[k] = rightList[j];
      j++;
    }
  }
  return list;
};

const mergeSort = function (list, beg, end) {
  if (end - beg > 1) {
    const middle = Math.ceil((end + beg) / 2);
    mergeSort(list, beg, middle);
    mergeSort(list, middle, end);
    merge(list, beg, middle, end);
  }
  return list;
};

module.exports = mergeSort;
