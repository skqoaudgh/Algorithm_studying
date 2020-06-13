let fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().split(' ');

const [N, r, c] = input.map(e => +e);
const size = Math.pow(2, N);
let count = 0;

function recursion(x, y, depth) {
    if(depth === 0) {
        console.log(count);
        return;
    }

    const size = Math.floor(Math.pow(2, depth-1) / 2);
    const skip = Math.pow(4, depth-1);
    if(r < x && c < y) { // 1사분면
        recursion(x - size, y - size, depth-1);
    } else if(r < x && c >= y) { // 2사분면
        count += skip;
        recursion(x - size, y + size, depth-1);
    } else if(r >= x && c < y) { // 3사분면
        count += skip*2;
        recursion(x + size, y - size, depth-1);
    } else { // 4사분면
        count += skip*3;
        recursion(x + size, y + size, depth-1);
    }
}

recursion(size/2, size/2, N);
