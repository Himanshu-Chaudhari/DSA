function calculate(a: number,
    b: number,
    operation: "sum" | "sub" | "mul" | "div"
): (number) {
    if (operation.toLowerCase() == "sum") {
        return a + b;
    }
    else if (operation.toLowerCase() == "sub") {
        return a - b;
    }
    else if (operation.toLowerCase() == "mul") {
        return a * b;
    }
    else if (operation.toLowerCase() == "div") {
        return a / b;
    }
    else {
        return -1;
    }
}
console.log("hello");
console.log(calculate(1, 2, "sum"))
console.log(calculate(23, 45, "sub"))
console.log(calculate(23, 45, "mul"))
console.log(calculate(23, 45, "div"))
