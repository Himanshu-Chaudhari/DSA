let p=document.getElementById("insert")

let func= async ()=>{
    step1=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("Initialising Hack")
        },3000)
    })

    step2=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("Hacking user name")
        },6000)
    })

    step3=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("User Name found")
        },9000)
    })

    step4=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("Hacking Facebook")
        },12000)
    })

    let a=await step1
    console.log(a)
    p.innerHTML=a;
    let b=await step2
    console.log(b)
    p.innerHTML=b;
    let c=await step3
    console.log(c)
    p.innerHTML=c;
    let d=await step4
    console.log(d)
    p.innerHTML=d;
}
func()

