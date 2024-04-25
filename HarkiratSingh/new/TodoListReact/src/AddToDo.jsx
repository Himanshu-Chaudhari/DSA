import React,{useState} from 'react'

export default function AddToDo() {
    const [title,setTitle]=useState('')
    const [description,setDescription]=useState('')
  return (

    <div>
        <div className='card' style={{marginLeft: '20vw' , marginRight: '20vw'}}>
            <div className="card-header ">Enter Title and Discription of Todo</div>
            <input className="form-control" type="text" placeholder="Title" onChange={(e)=>{
                setTitle(e.target.value)
            }}></input>
            <input className="form-control" type="text" placeholder="Description" onChange={(e)=>{
                setDescription(e.target.value)
            }}></input>
            <button className="btn btn-outline-success my-sm-0" style={{
                marginLeft:"10vw",
                marginRight:"10vw"
            }} onClick={()=>{
                if(title=='' || description==''){
                    alert('Please enter the title and description')
                }else{
                    fetch('http://localhost:3000/todos',{
                        method:'POST',
                        headers:{
                            'Content-Type' : 'application/json'
                        },
                        body:JSON.stringify({
                                "id" : Math.random(),
                                "title": JSON.stringify(title),
                                "discription": JSON.stringify(description),
                                "completed": false
                        })
                    }).then((res)=>{
                        res.json().then((data)=>{
                                // console.log(data)
                            }
                        )
                    })
                }
            }}>Add Todo</button>
        </div>
    </div>
    
  )
}
