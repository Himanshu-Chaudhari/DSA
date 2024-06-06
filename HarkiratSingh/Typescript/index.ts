
// // Interface and Types only exists in Typescript
// // function can not return Interface or Types 

// // Interface is used
// // To define the shape of parameter or class
// // They are also implemented by class 
// // They can extend each other 

// interface Arguments{
//     a : number
//     b : number
//     c : string
//     type? : string // This becomes optional property 
// }

// function sum(params : Arguments): number{
//     return params.a+params.b
// }

// console.log(sum({a: 7 ,b: 8 ,c: "Bla Bla"}))

// interface Person{
//     name : string
//     age : number
//     greet(a : string) : string
// }

// class DemoPerson implements Person{
//     name : string
//     age : number
//     constructor(name : string,age : number){
//         this.name=name
//         this.age=age
//     }

//     greet(a:string){
//         return a + this.name
//     }
// }

// const temp = new DemoPerson("Himanshu",6)

// console.log(temp.greet("Sayy Hello !"))


// // Types are used for doing uniion or intersection of interfaces or any other elements

// interface Circle {
//     radius ?: number
//     area : number
//     perimeter : number
// }
// interface Square {
//     side ?: number
//     area : number
//     perimeter : number
// }
// interface Rectangle {
//     length ?: number
//     breadth ?: number
//     area : number
//     perimeter : number
// }
// interface Triangle {
//     side1 ?: number
//     side2 ?: number
//     side3 ?: number
//     area : number
//     perimeter : number
// }

// type Shape = Square | Rectangle | Triangle | Circle

// function CalculateArea(parameter : Shape){
//     console.log(" Area Caluculated ")
// }

// CalculateArea({
//     side : 34,
//     area : 34,
//     perimeter : 34
// })


// // A function can retur n an enum
// // Enum 
// enum Operation{
//     Add,
//     Sub,
//     Mul,
//     Div
// }
// // Here int this enum Add , Sub , Mul , Div are assigned with default values of 0 , 1 , 2 , 3
// // Lets check it 

// function runningEnums(a: number , b:Operation){
//     console.log(b)
// }
// runningEnums(45,Operation.Div)



// Type Inference of typeScript :- (Google it)

// Array type 

function getFirst(array : number[]){
    return array[0];
}

let ans=getFirst([2,3,4,5,6,7,8,8]);
console.log(ans);

// OR

type NumberArray=number[] | string[]
function getFirstElement(array : NumberArray){
    return array[0];
}

let ans2=getFirstElement([2,3,4,5,6,7,8,8]);
let ans3=getFirstElement(["Hello","I","am","Himanshu"]);

console.log(ans2);
console.log(ans3);


// In the above example the type of ans3 and ans2 is (number | string) , which is not expected. It creates multiple anamolies to resolve this issue typescript temples are introduced (same as c++ templates) also known as generics

function getStarting<T>(array:T[]):T{
    return array[0];
}

// Here if type is not passed explicitely the type of template it is recorgnised by the typescript by seeing the type of the input array
let ans4 : number =getStarting([2,3,4,5,6,7,8,8]);
let ans5 : string =getStarting <string> (["Hello","I","am","Himanshu"]);

console.log(ans4);
console.log(ans5);

function swap<T>( a: T[] , b:T, c:T ) : T[]{
    let index1  : number=-1;
    let index2  : number=-1;
    for (let i = 0; i < a.length; i++) {
        if (a[i] === b) {
            index1 = i;
            break;
        }
    }

    for (let i = 0; i < a.length; i++) {
        if (a[i] === c) {
            index2 = i;
            break;
        }
    }

    let temp=a[index1]
    a[index1]=a[index2]
    a[index2]=temp

    return a;
}

let ansAfterSwap=swap([3,5,6,7,4,3,5,7,8,],6,8);
console.log(ansAfterSwap)


let swap2 = < T , J > ( a : T , b : J ) : [J , T]=>{
    return [b,a]
}

let ansAfterSwap2=swap2('r',true)
console.log(ansAfterSwap2)

//  Partial in TS

interface todo {
    title : string,
    description : string,
    id : number,
    comppleted : boolean
}

type UpdateTodo = Partial<todo>;
function updateTodo(id : number,toUpdateTodo : UpdateTodo){
}
updateTodo(1,{
    title: "hello"
})