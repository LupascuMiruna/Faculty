
with open("input.txt") as f:
    lines = f.read()

lines = lines.replace(":", "")
lines = lines.replace(",", "")
lines = [x for x in lines.split("\n")]
new = []
for line in lines:
    if line[0] != '#':
        new.append(line)

sigma = set()
states = set()
transitions = dict()

i = 0
while i != len(new):
    if new[i].strip() == 'Sigma':
        i += 1
        while new[i].strip() != 'End':
            new[i] = new[i].strip()
            sigma.add(new[i])
            i += 1
    if new[i].strip() == 'States':
        i += 1
        while new[i].strip() != 'End':
            new[i] = new[i].strip()
            state = []
            state = new[i].split()
            if len(state) == 1:
                states.add((state[0],))
            else:
                states.add(tuple(state))
            i += 1
    if new[i].strip() == 'Transitions':
        i += 1
        while new[i].strip() != 'End':
            new[i] = new[i].strip().split(" ")
            transitions[tuple(new[i][:2])] = new[i][2]
            i += 1
    i += 1

def validare (sigma, states, transitions):
    def valid_sigma():
        for transition in transitions:
            if transition[1] not in sigma:
                print(transitions[transition], "is not a valid word. Problem reported at transition no.",i+1)
                break
        else:
            return 1

    def valid_states():
        states_only = [x[0] for x in states]
        for transition in transitions:
            if transitions[transition] not in states_only or transition[0] not in states_only:
                print(transitions[i][0], "is not a valid state. Problem reported at transition no.",i+1)
                break
        else:
            return 1
    if valid_sigma() == 1 and valid_states() == 1:
        print("We are good to go! :)")
        return True

def checkAlphabet(cuv, sigma):
    for letter in cuv:
        if letter not in sigma:
            print(letter, "nu se afla in alfabet")
            return False
    return True

print(transitions)
if validare(sigma,states,transitions) == True:
    while True:
        cuv = input()
        stare = 'S'
        ok = 1
        if checkAlphabet(cuv, sigma) == True:
            while len(cuv) > 0 and (stare, cuv[0]) in transitions:
                stare = transitions[(stare, cuv[0])]
                cuv = cuv[1:]
            if len(cuv) != 0:
                print("Cuvant respins")

            elif (stare, 'F') in states:
                print("Cuvantul este acceptat")
            else:
                print("Cuvant respins")







