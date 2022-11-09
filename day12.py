inputs = open("inputs/day12-inputs.txt", "r").read().split("\n")

# A component graph
import networkx

graph = networkx.Graph()
for i in inputs:
    node, neighbors = i.split(" <-> ")
    graph.add_edges_from((node, neighbor) for neighbor in neighbors.split(", "))

connected_to_zero = len(networkx.node_connected_component(graph, '0')) # Part 1: How many? Answer: 175
connected_components = networkx.number_connected_components(graph) # Part 2: How many? 

print(connected_to_zero, connected_components)
