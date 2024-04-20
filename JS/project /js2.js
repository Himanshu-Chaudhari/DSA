let url="https://kontests.net/api/v1/codeforces_gym"

let response=fetch(url)

response.then((v)=>{
    return v.json( )
}).then((v)=>{
    console.log(v)
    ihtml=""
    for(items in v){
        console.log(v[items])
        ihtml+=`
            <h1>Contest Name: ${v[items].name} </h1>
            <h1>Url: ${v[items].url} </h1>
            <h1>Start Time: ${v[items].start_time} </h1>
            <h1>End Time: ${v[items].end_time} </h1>
            <hr> 
        `
    }
    cont.innerHTML=ihtml
})