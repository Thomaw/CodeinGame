
const N = +readline();
const rooms = [...Array(N + 1)];

for (let i = 0; i < N; i++) {
    const room = readline().split` `;
    
    rooms[i] = {
        id: +room[0],
        money: +room[1],
        total: 0,
        next: [(room[2] == 'E') ? N : +room[2], (room[3] == 'E') ? N : +room[3]],
    };
}

rooms[N] = {id: N, money: 0, total: 0, next: []};

const edge = [0];
const explore = (v, i) => {
    if (rooms[v].money + rooms[v].total  > rooms[rooms[v].next[i]].total) {
        edge.push(rooms[v].next[i]);
        rooms[rooms[v].next[i]].total = rooms[v].money + rooms[v].total;
    }
};

while (edge.length > 0) {
    const current = edge.shift();
    
    if (current < N) {
        explore(current, 0);
        explore(current, 1);
    }
}

console.log(rooms[N].total);
