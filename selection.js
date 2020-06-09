const selectionSort = function(list) {
  for(let i = 0; i < list.length - 1; i++){
    let menor = list[i],
    index = i,
    sup
    for(let j = i+1; j < list.length; j++) {
      if(list[j] < menor){
        menor = list[j]
        index = j
      } 
    }
    sup = list[index]
    list[index] = list[i]
    list[i] = sup
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
  results.push(selectionSort(arr))
})

for(let j = 0; j < list.length ; j++){
  if(list[j].sort((a, b) => a - b).toString() === selectionSort(list[j]).toString() ) {
    console.log(`array ${j+1} was sorted correctly`)
  } else {
    console.log(`array ${j+1} wasn't sorted correctly, try again`)
    console.log(list[j].sort((a, b) => a - b))
    console.log(selectionSort(list[j]))
  }
}