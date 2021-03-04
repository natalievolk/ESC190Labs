def find_lowest(L, e):
    low = 0
    high = len(L)-1
    
    while high >= low:
        i = (high+low)//2
        if L[i] > e:
            high = i - 1
            
        elif L[i] < e:
            low = i + 1

        elif L[i] == e and (i == 0 or L[i-1] != e):
            return i

        elif L[i] == e:
            high = i-1

    return -1

def find_highest(L, e):
    low = 0
    high = len(L)-1
    
    while high >= low:
        i = (high+low)//2

        if L[i] > e:
            high = i - 1
            
        elif L[i] < e:
            low = i + 1

        elif L[i] == e and (i == len(L)-1 or L[i+1] != e):
            return i

        elif L[i] == e:
            low = i+1
    return -1

if __name__ == '__main__':
    L = [1, 1, 1, 1, 1]
    print(find_lowest(L, 1))
    '''
    print(find(L, 2))
    print(find(L, 3))
    print(find(L, 4))
    print(find(L, 5))
    print(find(L, 6))
    '''
