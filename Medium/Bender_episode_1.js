const State = {
  x: 0,
  y: 0,
  inverted: false,
  beerMode: false,
  direction: 'SOUTH'
};

const Directions = {
  NORTH: {y: -1, x: 0},
  EAST: {y: 0, x: 1},
  SOUTH: {y: 1, x: 0},
  WEST: {y: 0, x: -1},
  toString: function(x, y) {

    for (var dir in Directions) {
      if (Directions[dir].x === x && Directions[dir].y === y)
        return dir;
    }
  }
};

const [Y, X] = readline().split(' ').map(Number);

const Map = new Array(Y);
const Ports = [];
var Visited = {};

for (let y = 0; y < Y; y++) {
  let row = readline();
  Map[y] = new Array(X);
  for (let x = 0; x < X; x++) {
    Map[y][x] = row[x];

    if (row[x] === '@') {
      State.x = x;
      State.y = y;
    } else if (row[x] === 'T') {
      Ports.push({y: y, x: x});
    }
  }
}

(function() {

  const moves = [];

  while (Map[State.y][State.x] !== '$') {

    // Have we been here already?
    if (Visited[State.y + '-' + State.x] !== undefined) {
      // Find visit with the same setup
      for (var visit of Visited[State.y + '-' + State.x]) {
        if (visit.direction === State.direction && visit.inverted === State.inverted && visit.beerMode === State.beerMode) {
          print("LOOP");
          return;
        }
      }
    } else {
      Visited[State.y + '-' + State.x] = [];
    }

    // Mark position as visited
    Visited[State.y + '-' + State.x].push({
      inverted: State.inverted,
      direction: State.direction,
      beerMode: State.beerMode
    });

    switch (Map[State.y][State.x]) {
      case 'N':
        State.direction = "NORTH";
        break;

      case 'E':
        State.direction = "EAST";
        break;

      case 'S':
        State.direction = "SOUTH";
        break;

      case 'W':
        State.direction = "WEST";
        break;

      case 'I':
        State.inverted = !State.inverted;
        break;

      case 'B':
        State.beerMode = !State.beerMode;
        break;

      case 'T':
        var which = +(State.x === Ports[0].x && State.y === Ports[0].y);
        State.x = Ports[which].x;
        State.y = Ports[which].y;
    }
    moves.push(getMove());
  }

  for (var move of moves) {
    print(move);
  }
})();

function getMove() {

  var cur = Directions[State.direction];
  if (Map[State.y + cur.y][State.x + cur.x] === 'X' && State.beerMode) {
    Map[State.y + cur.y][State.x + cur.x] = ' ';
    Visited = {};
  } else if (Map[State.y + cur.y][State.x + cur.x] === 'X' && !State.beerMode || Map[State.y + cur.y][State.x + cur.x] === '#') {

    var directions;
    if (State.inverted)
      directions = [Directions.WEST, Directions.NORTH, Directions.EAST, Directions.SOUTH];
    else
      directions = [Directions.SOUTH, Directions.EAST, Directions.NORTH, Directions.WEST];

    for (var direction of directions) {
      switch (Map[State.y + direction.y][State.x + direction.x]) {
        case 'X':
        case '#':
          break;
        default:
          State.x+= direction.x;
          State.y+= direction.y;
          State.direction = Directions.toString(direction.x, direction.y);
          return State.direction;
      }
    }
  }

  State.x+= cur.x;
  State.y+= cur.y;
  return Directions.toString(cur.x, cur.y);
}
