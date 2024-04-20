
function LogResponse(result){
    console.log(result)
}

function CallBackFn(response){
    response.json().then(LogResponse)
    console.log(response)
}

let senObj={
    method : "GET"
}

fetch("http://localhost:3000/learnFetch?counter=20",senObj).then(CallBackFn)