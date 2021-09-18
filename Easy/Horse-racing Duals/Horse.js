let d = 999999;
let horses = []

const N = parseInt(readline());
for (let i = 0; i < N; i++) {
    const pi = parseInt(readline());
    horses.push(pi);
}

horses.sort(function(a, b){return a-b});

for (let i = 0; i < N-1; i++) {
    d = Math.min(d,Math.abs(horses[i]-horses[i+1]));
}

console.log(d);
