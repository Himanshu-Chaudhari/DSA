import { useState, useEffect } from 'react'

function useTodo() {
  const [todos, setTodos] = useState([{
    id: "1",
    title: "Go to gym",
    discription: " Go to gym by walking"
  }])

  useEffect(() => {
    fetch("http://localhost:3000/todos").then((res) => [
      res.json().then((data) => {
        console.log(data)
        setTodos(data)
      })
    ])
    setInterval(() => {
      fetch("http://localhost:3000/todos").then((res) => [
        res.json().then((data) => {
          console.log(data)
          setTodos(data)
        })
      ])
    }, 3000)
  }, [])
  return todos
}

function TodoToDisplay(props) {
  let todos = useTodo()
  return (
    <>
      {todos.map((todo) => {
        return <div className="div">
          <TodoList todo={todo}></TodoList>
        </div>
      })}
    </>
  )
}

function TodoList(props) {
  function Delete(props) {
    fetch("http://localhost:3000/todos/" + props.id, {
      method: "DELETE"
    }).then((res) => (
      res.json().then((err) => {
        console.log(err)
      })
    ))
  }
  return <div className='d-flex flex-column align-items-center card ' style={{
    marginLeft: '20vw',
    marginRight: '20vw'
  }}>
    <div className='p-4 d-flex'>
      <h4>{props.todo.title}:-{props.todo.discription}</h4><button className='btn btn-primary' style={{
        marginLeft: '2vw'
      }} onClick={() => { Delete(props.todo) }}>Done</button>
      <br />
    </div>
  </div>
}

export default TodoToDisplay;