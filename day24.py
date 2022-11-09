def gen_bridges(bridge, components):
    bridge = bridge or [(0, 0)]
    cur = bridge[-1][1]
    for b in components[cur]:
        if not ((cur, b) in bridge or (b, cur) in bridge):
            new = bridge+[(cur, b)]
            yield new
            yield from gen_bridges(new, components)

from collections import defaultdict
def parse_components(input):
    components = defaultdict(set)
    for l in open("day24-inputs.txt").read().split("\n"):
        a, b = [int(x) for x in l.split('/')]
        components[a].add(b)
        components[b].add(a)
    return components

def solve(input):
    components = parse_components(input)
    mx = []
    for bridge in gen_bridges(None, components):
        mx.append((len(bridge), sum(a+b for a, b in bridge)))
    return mx

solution = solve(input)
part1 = sorted(solution, key=lambda x: x[1])[-1][1]
part2 = sorted(solution)[-1][1]
print(part1, part2)
