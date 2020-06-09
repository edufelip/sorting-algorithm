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
const results = []

list.forEach(arr => {
  results.push(quickSort(arr, 0, arr.length))
})

for(let j = 0; j < list.length ; j++){
  const jsSort = list[j].sort((a, b) => a - b)
  const qSort = quickSort(list[j], 0, list[j].length)
  if(jsSort === qSort) {
    console.log(`array ${j+1} was sorted correctly`)
  } else {
    console.log(`array ${j+1} wasn't sorted correctly, try again`)
    console.log(jsSort)
    console.log(qSort)
  }
}