let fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().split(' ');

const numbers = input.map(e => +e);

console.log(numbers.sort((a, b) => a - b).join(' '));
