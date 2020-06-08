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

const list = [
  [1, 3, 2, 5, 4],
  [9, 2, 8, 3, 7],
  [1, 3, 2, 5, 4, 9, 8, 12, 0],
  [9, 0, 9, 0]
]
const check = [
  [1, 2, 3, 4, 5],
  [2, 3, 7, 8, 9],
  [0, 1, 2, 3, 4, 5, 8, 9, 12],
  [0, 0, 9, 9]
]
const results = []

list.forEach(arr => {
  results.push(quickSort(arr, 0, arr.length - 1))
})

for(let i = 0; i < list.length ; i++){
  if(check[i].toString() === results[i].toString()) {
    console.log(`array ${i+1} was sorted correctly`)
  } else {
    console.log(`array ${i+1} wasn't sorted correctly, try again`)
  }
}