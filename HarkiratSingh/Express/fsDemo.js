const fs= require('fs')

function callback(err, data){ 
    console.log(data)

}
fs.readFile('/Users/himanshuchaudhari/Desktop/code/projects/Express/a.txt','utf-8',callback)