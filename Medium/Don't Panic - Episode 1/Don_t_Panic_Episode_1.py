nb_floors, width, nb_rounds, exit_floor, exit_pos, nb_total_clones, nb_additional_elevators, nb_elevators = [int(i) for i in input().split()]
elevators = {}
for i in range(nb_elevators):
    elevator_floor, elevator_pos = [int(j) for j in input().split()]
    elevators[elevator_floor] = elevator_pos
    
while True:
    clone_floor, clone_pos, direction = input().split()
    clone_floor = int(clone_floor)
    clone_pos = int(clone_pos)

    if (clone_floor < 0) or (clone_floor == exit_floor):
        direction2Exit = ("RIGHT", "LEFT")[exit_pos - clone_pos > 0]
        result = ("BLOCK", "WAIT")[direction2Exit != direction]
    else:
        elevator_pos = elevators[clone_floor]
        direction2Elevator = ("RIGHT", "LEFT")[elevator_pos - clone_pos > 0]

        if (elevator_pos - clone_pos == 0):
            result = "WAIT"
        else:
            result = ("BLOCK", "WAIT")[direction2Elevator != direction]

    print(result)
