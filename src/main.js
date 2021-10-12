const addon = require('../build/Release/addon.node');

const value = 8;    
console.log(`${value} times 2 equals`, addon.timesTwo(value));
console.log('returned object: ', addon.returnObject());
console.log('returned array: ', addon.returnArray());