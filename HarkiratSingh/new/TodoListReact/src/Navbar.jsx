import React from 'react'

export default function Navbar() {
  return (
    <div>
        <nav className="navbar bg-light">
            <div className="mx-4 navbar-brand " href="#">Himanshu's Todo App</div>
            <div>
                <button className="btn btn-outline-success my-2 my-sm-0" type="submit">Sign Up</button>
                <button className="btn btn-outline-success my-2 mx-3 my-sm-0"type="submit">Sign In</button>
            </div>
        </nav>
    </div>
  )
}
