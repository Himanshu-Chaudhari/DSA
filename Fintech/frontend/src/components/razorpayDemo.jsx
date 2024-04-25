import axios from 'axios';
import { useState } from 'react';

export default function RazorpayDemo() {
    
    let [amount,setAmount] = useState(0)
    const handleOnClick = async () => {
      
            const { data : {order} } = await axios.post("http://localhost:4000/checkout",{
                amount:amount
            });
            // console.log(window);
        

            const { data : {key} } = await axios.get("http://localhost:4000/getkey");
            // console.log(window);
            console.log(key)


        const options = {
            key : key, 
            amount : amount,
            currency : "INR",
            name : "Himanshu Chaudhari",
            description : "Test Transaction",
            image : "https://example.com/your_logo",
            order_id: order.id, 
            callback_url: "https://upload.wikimedia.org/wikipedia/commons/e/ef/Virat_Kohli_during_the_India_vs_Aus_4th_Test_match_at_Narendra_Modi_Stadium_on_09_March_2023.jpg",
            prefill: { 
                name: "Gaurav Kumar", 
                email: "gaurav.kumar@example.com",
                contact: "9000090000"
            },
            notes: {
                address: "Razorpay Corporate Office"
            },
            theme: {
                "color": "#3399cc"
            }
        };
        var rzp1 = new window.Razorpay(options);
        rzp1.open();

    };

    return (
        <div>
            <input type="number"
                value={amount}
                onChange={(e) => setAmount(e.target.value)}
                placeholder="Enter Amount to pay"
            />
            <button onClick={handleOnClick}>Click me</button>
        </div>
    );
}
