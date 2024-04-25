//Prototypes in javascript

// Javascript obejcts have a special property called prototype that is either NULL or refers another object

// const harr={
//     "harry":"thus",
//     "name":"carr"
// }
// console.log(harr)

// let p={
//     run:()=>{
//         alert("run")
//     }
// }

// harr.__proto__=p
// harr.run()


// ______-------------------_____

//Classes 

// class RailwayForm{
//     submit(){
//         alert(this.name+"form Submited")
//     }
//     cancel(){
//         alert(this.name+"form Canceled")
//     }
//     fill(name){
//         this.name=name;
//     }
// }

// let ob1=new RailwayForm()
// ob1.fill("OB1 ")
// let ob2=new RailwayForm()
// ob2.fill("OB2 ")

// ob1.submit()
// ob2.cancel()

//Constructor
// class RailwayForm {
//     submit() {
//         alert(this.name + " form Submited")
//     }
//     cancel() {
//         alert(this.name + " form Canceled")
//     }
//     constructor(name,trainno) {
//         this.name = name
//         this.trainno=trainno
//     }
// }

// let ob1=new RailwayForm("Ram",45)
// ob1.cancel()
 

// Inheritance in js is achieved through extends keyword

// class animal{
//     constructor(name , color){
//         this.name=name
//         this.color=color
//     }

//     bark(){
//         console.log(this.name+" is barking loudly")
//     }

//     eat(food){
//         console.log(this.name+" is eating "+food)
//     }
// }

// class monkey extends animal{
//     jump(){
//         console.log(this.name+" is jumping")
//     }
// }

// let ani = new animal("chetta","brown")
// let mnky = new monkey("Mnky","Orange")

// ani.bark()
// mnky.eat("banana")
// mnky.jump()

// check method overriding + super keyword (used to call function of parent class from base class functions(super.function_name()) and also parent class constructor(super())

//it is mandatory to use super (parent class constructor in child class constructor) this constructor should be called before using the word this iun child class constructor

// Static functions are those which belong to the class as a whole not to any perticular object can be awoked or used by using the name of the class  


// // Getter Setter and Instance of an operator

// class GetSetGo{
//     constructor(name){
//         this._name=name;
//     }

//     run(){
//         console.log(`${this._name} is running`)
//     }

//     get name(){
//         return this._name
//     }

//     set name(name){
//         this._name=name
//     }
// }

// let obj=new GetSetGo("Name1")

// obj.run();

// console.log(obj.name)

// obj.name="Name2"

// console.log(obj.name)

// console.log(obj instanceof GetSetGo)


// -------------------Practice Set--------------------------

// class Complex{
//     constructor(real,i){
//         this._real=real
//         this._i=i
//     }

//     get real(){
//         return this._real
//     }
//     get i(){
//         return this._i
//     }

//     static add(a,b){
//         let c = new Complex(a.real+b.real,b.i+a.i)
//         return c
//     }
// }


// let a=new Complex(6,7)
// let b=new Complex(6,7)

// let c=Complex.add(a,b)
// console.log(`Real = ${c._real} \nImaginary = ${c.i}`)

// -----------------------------------------------
// class Human{
//     constructor(name){
//         this.name=name;
//     }

//     run(){
//         console.log("Human is running")
//     }
// }

// class Student extends Human{
//     constructor(name){
//         super(name)
//         // this.name=name;
//     }

//     run(){
//         console.log(`${this.name} is running`)
//     }
// }

// let h=new Student("Man")
// h.run()

// console.log(h instanceof Human)


//----------------  IIFE (revise from GFG) -------------------

// // Destructuring assignment 

// let arr=[6,2,3,8,9]
// let [a,b,c,...rest]=arr
// console.log(a,b,c,rest)

// //spread operator
// let ob1={...arr}
// console.log(ob1)

// let sum=(a,b,c,d,e)=>{
//     return a+b+c+d+e
// }

// console.log(sum(...arr))

// Closures in javascript = This return all the internal ( lexical ) enviornment of the function while returning a function 
// let p= function(){
//     const x=()=>{
//         let a=2
//         console.log(a)
//         const y=()=>{
//             let a=3
//             console.log(a)
//             const z=()=>{
//                 let a=4
//                 console.log(a)
//             }
//             z()
//         }
//         y()
//     }
//     return x
// }
// q=p()
// q()

// Arrow function uses and returns the lexical scope of the function therefore they are better 

// let cal=async (message)=>{
//     let a=new Promise((resolve,reject)=>{
//         setTimeout(()=>{
//             resolve(message)
            
//         },2000)
    
//     })
//     return a
// }

// (
//     async ()=>{
//         let text=await cal("hello")
//         console.log(text)
//         text=await cal("world")
//         console.log(" "+text)
//     }
   
// )()

