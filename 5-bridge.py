def get_max_bridges(cities1, cities2):
    max_bridges = [[0] * len(cities2) for _ in range(len(cities1))]
    
    for city1_index, city1_order in enumerate(cities1):
        for city2_index, city2_order in enumerate(cities2):
            curr_max_bridges = 0
            if city1_index > 0:
                curr_max_bridges = max(curr_max_bridges, max_bridges[city1_index - 1][city2_index])
            if city2_index > 0:
                curr_max_bridges = max(curr_max_bridges, max_bridges[city1_index][city2_index - 1])
            if city1_order == city2_order and city1_index > 0 and city2_index > 0:
                curr_max_bridges = max(curr_max_bridges, max_bridges[city1_index - 1][city2_index - 1] + 1)
                
            max_bridges[city1_index][city2_index] = curr_max_bridges
            
    return max_bridges[-1][-1]

print(get_max_bridges([1, 4, 2, 5, 3], [3, 2, 4, 1, 5])) # 2
        