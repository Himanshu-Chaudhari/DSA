const express = require('express');
require('dotenv').config();
const app = express();
const bodyParser = require('body-parser')
const cors = require('cors');
const razorpay = require('razorpay');
const mongoose = require('mongoose');
app.use(cors());
app.use(bodyParser.json());

const instance = new razorpay({
    key_id: process.env.RAZORPAY_API_KEY,
    key_secret : process.env.RAZORPAY_SECRET,
})

app.post("/checkout",async (req,res)=>{
    try {
        const options = {
            amount: req.body.amount*100,
            currency: "INR"
        };
        const order = await instance.orders.create(options);
        console.log(order);
        res.json({
            success: true,
            order,
        });
    } catch (error) {
        console.error("Error creating order:", error);
        res.status(500).send("Internal Server Error");
    }
})

app.get("/getkey",(req,res)=>{
    res.json({
        key : process.env.RAZORPAY_API_KEY
    })
})

app.listen(process.env.PORT,() => {
    console.log(process.env.RAZORPAY_API_KEY);
    console.log("Server running at port", process.env.PORT);
});