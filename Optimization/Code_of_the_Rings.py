import sys
import math
from string import ascii_uppercase

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

N_ZONES = 30
N_LETTERS = 26
magic_phrase = input()

print(magic_phrase, file = sys.stderr)

# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)
command = []

ord_chr = {}
ord_chr[' '] = 0
for i in range(len(ascii_uppercase)):
    ord_chr[ascii_uppercase[i]] = i+1

n = N_LETTERS

def letter_selection(curr_let, wanted_let):
    print(curr_let, "\t", wanted_let, file = sys.stderr)
    wanted_ord = ord_chr[wanted_let]
    curr_ord = ord_chr[curr_let]
    print("wanted_ord: ", wanted_ord, "curr_ord: ", curr_ord, file=sys.stderr)

    if wanted_ord == curr_ord:
        return ""
    else:
        down_cycle = curr_ord+n-wanted_ord+1    # +1 because of space
        up_cycle = n-curr_ord+wanted_ord+1
        no_cycle = abs(wanted_ord-curr_ord)

        min_mov = min(up_cycle, down_cycle, no_cycle)
        print("min_mov: ", min_mov, file=sys.stderr)
        if min_mov == up_cycle:
            print("more", file=sys.stderr)
            return "+" * up_cycle
        elif min_mov == down_cycle:
            print("less", file=sys.stderr)
            return "-" * down_cycle
        else:
            print("intra", file=sys.stderr)
            if wanted_ord > curr_ord:
                return "+" * no_cycle
            else:
                return "-" * no_cycle


current_letters = [" "] * N_ZONES        
for i in range(len(magic_phrase)):
    curr_let = current_letters[i % N_ZONES]
    command.append(letter_selection(curr_let, magic_phrase[i]))
    current_letters[i % N_ZONES] = magic_phrase[i]
    #print(''.join(current_letters), file=sys.stderr)
    
    command.append('.')
    if i < len(magic_phrase)-1:
        command.append('>')

print(''.join(command))
