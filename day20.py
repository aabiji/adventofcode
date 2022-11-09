inputs = open("day20-inputs.txt", "r").read().split("\n")

class Particle:
    def __init__(self, xyz, vel, acc, i):
        self.pos = xyz
        self.vel = vel
        self.acc = acc
        self.i = i
    
    def step(self):
        self.vel[0] += self.acc[0]
        self.vel[1] += self.acc[1]
        self.vel[2] += self.acc[2]

        self.pos[0] += self.vel[0]
        self.pos[1] += self.vel[1]
        self.pos[2] += self.vel[2]

    def dist(self):
        return abs(self.pos[0]) + abs(self.pos[1]) + abs(self.pos[2])

    def who(self):
        return self.i

particles = []
for i in range(len(inputs)):
    m = inputs[i].split(", ")
    xyz = [int(x) for x in m[0][3: len(m[0]) - 1].split(",")]
    vel = [int(x) for x in m[1][3: len(m[1]) - 1].split(",")]
    acc = [int(x) for x in m[2][3: len(m[2]) - 1].split(",")]
    particles.append(Particle(xyz, vel, acc, i))

# Part 2 -> How mnay particles after all collisions ruled out? Answer: 420
i = 0
while True:
    new_particles = []
    for p in particles: p.step()

    collision_count = 0
    for pg in particles:
        no_collisions = True
        for p in particles:
            if pg.pos == p.pos and pg.who() != p.who():
                no_collisions = False
                collision_count += 1
                break
        if no_collisions:
            new_particles.append(pg)   
    particles = new_particles.copy()

    print(len(particles), collision_count)

    i += 1

# Part 1 -> Which particle stays closest to origin in the 'long run'? Answer: 364
'''
p = 100000000
n = 0
for i in range(len(particles)):
    acc = abs(particles[i].acc[0]) + abs(particles[i].acc[1]) + abs(particles[i].acc[2])
    if acc < p:
        n = i
        p = acc
print(n)
'''