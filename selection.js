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

module.exports = selectionSort