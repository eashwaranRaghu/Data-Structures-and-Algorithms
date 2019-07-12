const S1 ="cba";
const S2 ="abcdefghijklmnopqrstuvwxyz";
Obj = {};
for (let index = 0; index < S2.length; index++) {
    Obj[S2[index]] = index;
}
let pos = 0;
for (let index = 0; index < S1.length; index++) {
    const element = S1[index];
    pos += Math.abs(pos - Obj[element]);
    pos = element;
}
console.log(pos);