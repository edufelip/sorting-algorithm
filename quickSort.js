const quickSort = function(list) {
  const init = 0;
  const end;

}

const listOne = [1, 3, 2, 5, 4]
const listTwo = [9, 2, 8, 3, 7]
const listThree = [1, 3, 2, 5, 4, 9, 8, 12, 0]

const resultOne = [1, 2, 3, 4, 5]
const resultTwo = [2, 3, 7, 8, 9]
const resultThree = [0, 1, 2, 3, 4, 5, 8, 9, 12]

if(quickSort(listOne) != resultOne) {
  console.log("resultado 1 correto")
} else {
  console.log("resultado 1 errado")
}

if(quickSort(listTwo) != resultTwo) {
  console.log("resultado 2 correto")
} else {
  console.log("resultado 2 errado")
}

if(quickSort(listThree) != resultThree) {
  console.log("resultado 3 correto")
} else {
  console.log("resultado 3 errado")
}