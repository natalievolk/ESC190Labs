import numpy as np

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False


def connect(node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight})
    node2.connections.append({"node": node1, "weight": weight})


def BFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True


################################################################################

def get_all_nodes(node):
    '''Return a list of the nodes in the graph of nodes connected to node
    (N.B., the nodes can be indirectly connected as well)'''
    connected = []
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        connected.append(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True
    return connected

################################################################################

def unvisit_all(node):
    '''Change all n.visited to False in all the nodes in the graph of nodes
    connected to node. Use BFS to find all the nodes'''
    q = [node]
    node.visited = False
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        #print(cur.name)
        for con in cur.connections:
            if  con["node"].visited:
                q.append(con["node"])
                con["node"].visited = False



###############################################################################

def DFS_rec(node):
    '''Print out the names of all nodes connected to node using a
    recursive version of DFS'''
    node.visited = True
    print(node.name)

    for con in node.connections:
        if not con["node"].visited:
            con["node"].visited = True
            DFS_rec(con["node"])


################################################################################

def DFS_nonrec(node):
    '''Print out the names of all nodes connected to node using a non-recursive
    version of DFS. Make it so that the nodes are printed in the same order
    as in DFS_rec'''
    s = [node]
    node.visited = True

    while len(s) > 0:
        
        cur = s.pop(-1)
        print(cur.name)
        cur.visited = True
        for i in range(len(cur.connections)-1, -1, -1):
            con = cur.connections[i]
            if not con["node"].visited and con["node"] not in s:
                s.append(con["node"])



################################################################################
#
# OPTIONAL
#

def dijsktra_slowish(node):
    '''Implement Dijkstra's algorithm as discussed in class (i.e., you don't
    need to use a priority queue'''
    S = [node]
    d = {node.name: 0}

    unexplored = get_all_nodes(node)
    unexplored.remove(node)

    while len(unexplored) > 0:
        # your code here
        pass

    return d




if __name__ == '__main__':
    TO = Node("TO")
    NYC = Node("NYC")
    DC = Node("DC")
    CDMX = Node("CDMX")
    SF = Node("SF")
    SEA = Node("SEA")

    connect(TO, NYC, 3)
    connect(TO, SF, 6)
    connect(TO, CDMX, 7)
    connect(NYC, DC, 2)
    connect(SF, DC, 5)
    connect(DC, SEA, 3)

    #DFS_rec(TO)

    unvisit_all(NYC)

    DFS_nonrec(TO)
    
    #BFS(TO)

    '''
    

    connected = get_all_nodes(TO)
    for i in connected:
        print(i)
    '''

    '''
    L = get_all_nodes(TO)
    DFS(TO)
    #DFS_rec(TO)
    unvisit_all(TO)
    DFS(TO)
    print(dijsktra_slowish(TO))
    '''