const selectionSort = require("./selection")
const quickSort = require("./quick")
const bubbleSort = require("./bubble")
const insertionSort = require("./insertion")

const list = [
  [1, 3, 2, 5, 4],
  [9, 2, 8, 3, 7],
  [1, 3, 2, 5, 4, 9, 8, 12, 0],
  [9, 0, 9, 0]
]

for(let j = 0; j < list.length ; j++){
  const jsSort = list[j].sort((a, b) => a - b)
  const sSort = insertionSort(list[j])
  if(jsSort === sSort) {
    console.log(`array ${j+1} was sorted correctly`)
  } else {
    console.log(`array ${j+1} wasn't sorted correctly, try again`)
    console.log(jsSort)
    console.log(sSort)
  }
}