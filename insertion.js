const insertionSort = function(list){
  for(let i = 1; i < list.length; i++){
    let key = list[i]
    let j = i - 1
    while(j >= 0 && list[j] > key) {
      list[j + 1] = list[j]
      j--
    }
    list[j + 1] = key
  }
  return list
}

module.exports = insertionSort

