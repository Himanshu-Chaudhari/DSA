import { useState } from 'react'
import SignUp from './Components/SignUp'
import './App.css'
import NavBar from './Components/NavBar'
import CoursesUser from './Components/CoursesUser'
import CourseAdmin from './Components/CourseAdmin'
import { Route ,Routes } from 'react-router-dom'
import {BrowserRouter as Router} from 'react-router-dom'
import {RecoilRoot,atom,selector,useRecoilState,useRecoilValue} from 'recoil'

function App() {

  return (
    <>
      <RecoilRoot>
        <Router>
          <Routes>
            <Route index element={<><NavBar/><br/><br/><SignUp/></>} />
            <Route path='/navbar' element={ <><NavBar/></>}/>
            <Route path='/courseUser' element={ <><NavBar/><CoursesUser/></>}/>
            <Route path='/courseAdmin' element={ <><NavBar/><br/><br/><CourseAdmin/></>}/>
            </Routes>
        </Router>
      </RecoilRoot>
    </>
  )
}

export default App
