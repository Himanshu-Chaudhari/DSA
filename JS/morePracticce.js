f=document.getElementById('first')
s=document.getElementById('second')
t=document.getElementById('third')


s.addEventListener('click',function(){
    alert("You clicked on second")
})

t.addEventListener('click',function(){
    alert("You clicked on third")
})

document.getElementById('google').addEventListener('click',function(){
    window.open("https://www.google.com",'_blank')
    win.focus();
})

setInterval(function(){
    document.querySelector('#dabba').classList.toggle('one')
},300)


setInterval(function(){
    let currentTime=new Date()
    let currentHour=currentTime.getHours();
    let currentMinute=currentTime.getMinutes();
    let currentsec=currentTime.getSeconds()
    // console.log(currentHour,currentMinute,currentsec)
    let ans=String(currentHour+' : '+currentMinute+' : '+currentsec)
    // console.log(ans)
    document.getElementById('clock').innerHTML=ans
},1000)

