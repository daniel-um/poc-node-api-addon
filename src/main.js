const addon = require('../build/Release/addon.node');

const value = 8;    
console.log(`${value} times 2 equals`, addon.myFunction(value));