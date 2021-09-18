const n = +readline();

for (let i=1; i<=n; i++){
    if (n**2 % i ===0) console.log("1/%d = 1/%d + 1/%d", n, n**2/i+n, i+n);
}
