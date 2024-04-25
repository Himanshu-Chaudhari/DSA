import Navbar from './Navbar'
import TodoToDisplay from './TodoList'
import { Route ,Routes } from 'react-router-dom'
import ReactDOM from "react-dom/client";
import AddToDo from './AddToDo'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import {BrowserRouter as Router} from 'react-router-dom';

function App() {
  return (
    <>
      <Router>
        <Routes>
        <Route index element={<><Navbar/><br/><br/><AddToDo/><br/><br/><TodoToDisplay/></>} />
          <Route path='/home' element={ <><Navbar/><br/><br/><AddToDo/><br/><br/><TodoToDisplay/></>}/>
          <Route path='/Navbar' element={ <><Navbar/></>}/>
          <Route path='/AddTodo' element={ <><AddToDo/></>}/>
          <Route path='/TodoToDisplay' element={ <><TodoToDisplay/></>}/>
        </Routes>
      </Router>
    </>
  )
}
export default App
