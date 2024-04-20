let multiply=(arr)=>{
    arr = arr.filter((a)=>{
        return a!=7
    })
    return arr
}
let arr=[6,7,8,9,0,6]
let newArr=multiply(arr)
console.log(newArr)