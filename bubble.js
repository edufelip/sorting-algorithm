const bubbleSort = function(list) {
  for(let i = 0; i < list.length - 1; i++) {
    for(let j = 0; j < list.length - 1; j++){
      if(list[j] > list[j+1]) {
        let sup = list[j]
        list[j] = list[j + 1]
        list[j + 1] = sup
      }
    }
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
  results.push(bubbleSort(arr))
})

for(let j = 0; j < list.length ; j++){
  if(list[j].sort((a, b) => a - b).toString() === bubbleSort(list[j]).toString() ) {
    console.log(`array ${j+1} was sorted correctly`)
  } else {
    console.log(`array ${j+1} wasn't sorted correctly, try again`)
    console.log(list[j].sort((a, b) => a - b))
    console.log(bubbleSort(list[j]))
  }
}