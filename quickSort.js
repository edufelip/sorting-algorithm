const quickSort = function(list, beg, end) {
  let init = beg || 0
  let finish = init
  const pivotIndex = end || list.length - 1 
  const pivot = list[pivotIndex]
  while(finish < pivotIndex - 1) {
    finish++
    if(list[finish] < pivot) {
      let sup = list[finish]
      list[finish] = list[init]
      list[init] = sup
      init++
    }
  }
  list.splice(init, 0, list[pivotIndex])
  list.pop()
  // quickSort()
  console.log(list)
  return list
}
quickSort([4, 7, 2, 6, 4, 1, 8, 3])


// const listOne = [1, 3, 2, 5, 4]
// const listTwo = [9, 2, 8, 3, 7]
// const listThree = [1, 3, 2, 5, 4, 9, 8, 12, 0]

// const resultOne = [1, 2, 3, 4, 5]
// const resultTwo = [2, 3, 7, 8, 9]
// const resultThree = [0, 1, 2, 3, 4, 5, 8, 9, 12]

// if(quickSort(listOne) != resultOne) {
//   console.log("resultado 1 correto")
// } else {
//   console.log("resultado 1 errado")
// }

// if(quickSort(listTwo) != resultTwo) {
//   console.log("resultado 2 correto")
// } else {
//   console.log("resultado 2 errado")
// }

// if(quickSort(listThree) != resultThree) {
//   console.log("resultado 3 correto")
// } else {
//   console.log("resultado 3 errado")
// }