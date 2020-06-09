const quickSort = function(list, low, high) {
  let init = low
  let finish = init
  const pivotIndex = high
  const pivot = list[pivotIndex]
  while(finish <= pivotIndex - 1) {
    if(list[finish] < pivot) {
      let sup = list[finish]
      list[finish] = list[init]
      list[init] = sup
      init++
    }
    finish++
  }
  if(init >= low) {
    list.splice(init, 0, list[pivotIndex])
    list.splice(pivotIndex + 1, 1)
    if(init - low > 1) quickSort(list, low, init - 1)
    if(high - init > 1) quickSort(list, init + 1, high)
  }
  return list
}

module.exports = quickSort