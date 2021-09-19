var inputs = readline().split(' ');
const nbFloors = parseInt(inputs[0]);               // number of floors
const width = parseInt(inputs[1]);                  // width of the area
const nbRounds = parseInt(inputs[2]);               // maximum number of rounds
const exitFloor = parseInt(inputs[3]);              // floor on which the exit is found
const exitPos = parseInt(inputs[4]);                // position of the exit on its floor
const nbTotalClones = parseInt(inputs[5]);          // number of generated clones
const nbAdditionalElevators = parseInt(inputs[6]);  // ignore (always zero)
const nbElevators = parseInt(inputs[7]);            // number of elevators
let elevatorFloor = [];
let elevatorPos = [];

for (let i = 0; i < nbElevators; i++) {
    var inputs = readline().split(' ');
    elevatorFloor.push(parseInt(inputs[0]));      // floor on which this elevator is found
    elevatorPos.push(parseInt(inputs[1]));        // position of the elevator on its floor
    
}

// game loop
while (true) {
    var inputs = readline().split(' ');
    const cloneFloor = parseInt(inputs[0]); // floor of the leading clone
    const clonePos = parseInt(inputs[1]);   // position of the leading clone on its floor
    const direction = inputs[2];            // direction of the leading clone: LEFT or RIGHT

    // S'il n'y a pas d'ascenseur
    if (elevatorFloor.length == 0 || elevatorFloor.indexOf(cloneFloor) == -1){SameFloor(elevatorFloor, exitPos, clonePos, direction);}
    // S'il y a un ascenseur, il faut le trouver
    else{SameFloor(elevatorFloor, elevatorPos[elevatorFloor.indexOf(cloneFloor)], clonePos, direction)}
}


function SameFloor(elevatorFloor, exitPos, clonePos, direction){
        let d = exitPos - clonePos;

        if((d<0 && direction == 'RIGHT') || (d>0 && direction == 'LEFT')) {console.log('BLOCK');}
        else{console.log('WAIT');}
}
