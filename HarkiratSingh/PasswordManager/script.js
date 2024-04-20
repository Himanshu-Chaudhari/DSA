function copyText(txt){
    navigator.clipboard.writeText(txt).then(
        ()=>{
            // console.log(txt)
            alert("copied the text: " + txt )
        },
        ()=>{
            // console.log(txt)
            alert("failed to copy")
        },
    ); 
}

const deletePassword = (website) => {
    let data=localStorage.getItem("passwords")
    let arr=JSON.parse(data)
    arrUpdated=arr.filter((e)=>{
        return e.website!=website
    })
    localStorage.setItem("passwords",JSON.stringify(arrUpdated))
    alert(`Successfully deleted ${website} password `)
    showPasswords()
}

// Filling the table

const showPasswords = () => {
    let tb = document.querySelector("table")
    let data = localStorage.getItem("passwords")

    if (data == null) {
        tb.innerHTML = "No data to show"
    }
    else {
        tb.innerHTML = `<tr>
            <th>Name</th>
            <th>Website</th>
            <th>Password</th>
            <th>Delete</th>
            </tr>`
        let arr = JSON.parse(data)
        let str = ""
        for (let i = 0; i < arr.length; i++) {
            const ele = arr[i];
            str += `<tr>
        <td>${ele.username} <img onclick="copyText('${ele.username}')"  src="./copy.svg" alt="Copy Button" width="12" height="12" ></td>
        <td>${ele.website} <img onclick="copyText('${ele.website}')" src="./copy.svg" alt="Copy Button" width="12" height="12"></td>
        <td>${ele.password} <img onclick="copyText('${ele.password}')" src="./copy.svg" alt="Copy Button" width="12" height="12"></td>
        <td><button class="btnsm" id="${ele.website}" onclick="deletePassword('${ele.website}')" >Delete</button></td>
        </tr>`
        }
        tb.innerHTML = tb.innerHTML + str
    }
    website.value=""
    username.value=""
    password.value=""
}

showPasswords()

console.log("Working")
document.querySelector(".btn").addEventListener("click", (e) => {
    e.preventDefault()
    console.log(username.value, password.value, website.value)
    let passwords = localStorage.getItem("passwords")
    console.log(passwords)
    if (passwords == null) {
        //creating an empty array
        let json = []
        //adding an object to the array
        json.push({ username: username.value, password: password.value, website: website.value })
        alert("password saved")
        localStorage.setItem("passwords", JSON.stringify(json))
    }
    else {
        let json = JSON.parse(localStorage.getItem("passwords"))
        json.push({ username: username.value, password: password.value, website: website.value })
        alert("password saved")
        localStorage.setItem("passwords", JSON.stringify(json))

    }
    showPasswords()
})