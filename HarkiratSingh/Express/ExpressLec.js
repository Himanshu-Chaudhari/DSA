// Creating a http server using express

// Notes:- 4 types of request in express
// GET
// PUT
// Post
// Delete

// Middle Wares in Express Js

// Default status code responded by express is 200 (Check status codes like successful , error from goggle)

//body can also return 1.HTML 2.JSON 3.Text
const express = require('express')
var bodyParser=require('body-parser')
const app = express()
const port = 3000

let noOfRequest=0;

// function middleware1(req,res,next){
//     noOfRequest++;
//     console.log("Inside a middleWare and no requests are ",noOfRequest)
//     next();
// }
// app.use(middleware1);


//It is a middleware to use JSON passed through the body
app.use(bodyParser.json())

function calculateSum(a){
    let sum=0;
    for(let i=0 ;i<=a;i++){
        sum=sum+i
    }
    console.log(sum)
    return sum
}

function handleSumRequest(req , res){

    // Taking parameters from query
    // let count1=req.query.counter1
    // let count2=req.query.counter2

    //Taking parameters from headers
    // let count1=req.headers.counter1
    // let count2=req.headers.counter2

    // Taking parameters from body // Here we need to add body-parser middleware to access the data being passed through the body

    let count1=req.body.counter1
    let count2=req.body.counter2

    // console.log(count1)
    // console.log(count2)
    if(count1 != count2){
        var sum1=calculateSum(count1)
        var sum2=calculateSum(count2) 
        // To return a string as a response
        // res.send(`Sum is ${sum1},${sum2}`)

        // To return a JSON as a response
        let obj={
            s1:sum1,
            s2:sum2
        }
        res.status(200).send(obj)
    }
    else{
        res.status(414).send("Enter different entries")
    }
}


// Function to send html 
function givePage(req,res){
    res.send(`<head><title>Hello from Page</title></head><body><i><b>Hii From Body<i></b></body>`)
}

// Function to send html directly from a file
// function givePage(req,res){
//     res.sendFile(__dirname+'/index.html')
// }

app.get('/htmlPage',givePage)
function handleFirstRequest(req , res){
    res.send('First request handeled')
}

// app.get('/sum', handleSumRequest)
app.put('/',handleFirstRequest)
app.delete('/',handleFirstRequest)
app.post('/',handleSumRequest)
function started(){
    console.log(`Example port running on port ${port}`)
}

app.listen(port, started)



function handleSum(req,res){
    let count=req.query.counter
    console.log(count)
    let sum=calculateSum(count)
    let obj={
        ans:sum
    }
    res.send(obj)
}

app.get("/learnFetch",handleSum)

