const selectionSort = require("./selection")
const quickSort = require("./quick")
const bubbleSort = require("./bubble")
const insertionSort = require("./insertion")
const mergeSort = require("./merge")

const list = [
  [1, 3, 2, 5, 4],
  [9, 2, 8, 3, 7],
  [1, 3, 2, 5, 4, 9, 8, 12, 0],
  [9, 0, 9, 0],
  [1, 1, 1, 1, 0, 9, 1],
  [1, 2, 3, 4, 5, 6, 7, 9, 990, 1240],
  [999, 888, 777, 3, 2, 1]
]

for(let j = 0; j < list.length ; j++){
  const jsSort = list[j].sort((a, b) => a - b)
  const writtenSort = mergeSort(list[j])
  if(jsSort === writtenSort) {
    console.log(`array ${j+1} was sorted correctly`)
  } else {
    console.log(`array ${j+1} wasn't sorted correctly, try again`)
    console.log(jsSort)
    console.log(sSort)
  }
}