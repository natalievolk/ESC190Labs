# 2. Write Python code to find the cost of the minimum-energy seam in a list of lists.

energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19]]


energies2 = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      29,       27,      20,      19]]

    # The correct output for the given energies data is 15+10+13+17+7 = 62.

def min_energy(energies):
    cost = []
    for i in range(len(energies)):
        cost.append([0]*len(energies[0]))

    for i in range(len(energies[0])):
        cost[0][i] = energies[0][i]

    for i in range(1, len(energies)):
        for j in range(len(energies[0])):
            if j == 0:
                cost[i][j] = energies[i][j] + min(cost[i-1][j], cost[i-1][j+1])

            elif j == len(energies[0]) - 1:
                cost[i][j] = energies[i][j] + min(cost[i-1][j], cost[i-1][j-1])
            else:
                cost[i][j] = energies[i][j] + min(cost[i-1][j-1], cost[i-1][j], cost[i-1][j+1])


    for i in range(len(cost)):
        print(cost[i])
    return min(cost[-1])

min_energy(energies)