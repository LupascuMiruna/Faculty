f = open("input.txt")
l = f.read()
l = l.replace(":", "")
l = l.replace(",", "")

l = l.split("\n")

new = []
for linie in l:
    if linie[0]  != '#' and linie  !='':
        linie = linie.strip()
        new.append(linie)

sigma = set()
states = set()
transitions = []
i = 0
n = len(new)
l = new


i = 0
while i < n:
    if new[i] == 'States':
        i += 1
        while new[i] != 'End' and i < n:
            new[i] = new[i].strip()
            state = []
            state = new[i].split()
            if len(state) == 1:
                states.add((state[0],0,0))
            else:
                if len(state) == 2:
                    if state[1] == 'S':
                        states.add((state[0], state[1], 0))
                    else:
                        states.add((state[0], 0, state[1]))
                else:
                    states.add((state[0], state[1], state[2]))
            i += 1

    if new[i] == 'Sigma':
        i += 1
        while new[i] != 'End'and i < n:
            new[i] = new[i].strip()
            sigma.add(new[i])
            i += 1

    if new[i] == 'Transitions':
        i += 1
        while new[i] != 'End' and i < n:

            new[i] = new[i].strip()
            transition = []
            transition = new[i].split()
            transitions.append(transition)
            i += 1
    if new[i] == 'End':
        i += 1

#VERIFICAM DACA AVEM FIX O STARE DE INCEPUT SI CEL PUTIN UNA DE FINAL

def check_states(states):
    start = 0
    stop = 0
    for state in states:
        if state[1] == 'S':
            start += 1
        if state[2] == 'F':
            stop += 1


    if start != 1:
        print("Not correct number of S\n")
    if stop < 1:
        print("Not correct number of F\n")

    if start == 1 and stop >= 1:
        print("Everything OK\n")



check_states(states)

#VERIFICAM CA TRANZITIILE SA FIE BUNE

def validare (sigma, states, transitions):
    def valid_sigma():
        for i in range(len(transitions)):
            if transitions[i][1] not in sigma:
                print("At transition", i+ 1, transitions[i][1], "is not a valid word.")
                break
        else:
            return 1

    def valid_states():
        states_only = [x[0] for x in states]
        for i in range(len(transitions)):
            if transitions[i][0] not in states_only or transitions[i][2] not in states_only:
                print("At transition", i+ 1,transitions[i][0], "is not a valid state.")
                break
        else:
            return 1
    if valid_sigma() == 1 and valid_states() == 1:
        print("OK")


validare(sigma,states,transitions)