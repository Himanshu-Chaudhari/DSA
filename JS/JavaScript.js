// Snake Water Gun Game
// let snake = 1
// let water = 2
// let gun = 3

// choice = true
// while (choice) {
//     let usrScore = 0
//     let compScore = 0
//     let cnt = 10
//     while (cnt > 0) {
//         let usr = prompt("Snake : 1 , Water : 2 , Gun : 3")
//         usr = parseInt(usr)
//         if (usr > 3 || usr < 0) {
//             alert("Wrong entry")
//             break
//         }
//         let comp = Math.floor(Math.random() * 3 + 1)
//         if (usr == comp) {
//             alert("same choice \nUser choice : " + usr + " Comp choice" + comp + " \nUser: " + usrScore + " Comp: " + compScore)
//         }
//         else {
//             if (usr == 1) {
//                 if (comp == 2) {
//                     usrScore++
//                 }
//                 else {
//                     compScore++
//                 }
//             }
//             if (usr == 2) {
//                 if (comp == 1) {
//                     compScore++
//                 }
//                 else {
//                     usrScore++
//                 }
//             }
//             if (usr == 3) {
//                 if (comp == 1) {
//                     usrScore++
//                 }
//                 else {
//                     compScore++
//                 }
//             }
//             alert("User choice : " + usr + " Comp choice: " + comp + " \nUser: " + usrScore + " Comp: " + compScore)
//             // alert()
//         }
//         cnt--;
//     }
//     if (usrScore > compScore) {
//         alert("User Won")
//     }
//     else {
//         alert("Comp won")
//     }
//     alert("Final Score (User: " + usrScore + " Comp: " + compScore + ")")

//     choice = confirm("Do You want to play game once more")
// }

