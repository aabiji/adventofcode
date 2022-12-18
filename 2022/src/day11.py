
DIVISOR = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19
players = []
ops = {
	0: lambda x: x * 3,
	1: lambda x: x + 1,
	2: lambda x: x * 13,
	3: lambda x: x * x,
	4: lambda x: x + 7,
	5: lambda x: x + 8,
	6: lambda x: x + 4,
	7: lambda x: x + 5
}

class Monkey:
	def __init__(self, items, throws, test, index):
		self.throws = throws
		self.items = items
		self.test = test
		self.index = index
		self.inspect = 0

	def play(self):
		if len(self.items) == 0:
			return

		i = 0
		while i < len(self.items):
			#print(len(self.items))
			#print(self.items)

			self.inspect += 1
			num = ops[self.index](self.items[i]) % DIVISOR

			if divmod(num, self.test)[1] == 0:
				players[self.throws[0]].items.extend([num])
			else:
				players[self.throws[1]].items.extend([num])

			self.items = [x for index, x in enumerate(self.items) if index != i]
			i -= 1

			i += 1			

players = [Monkey([89, 73, 66, 57, 64, 80], [6, 2], 13, 0), Monkey([83, 78, 81, 55, 81, 59, 69], [7, 4], 3, 1), 
		   Monkey([76, 91, 58, 85], [1, 4], 7, 2), Monkey([71, 72, 74, 76, 68], [6, 0], 2, 3),
		   Monkey([98, 85, 84], [5, 7], 19, 4), Monkey([78], [3, 0], 5, 5),
		   Monkey([86, 70, 60, 88, 88, 78, 74, 83], [1, 2], 11, 6), Monkey([81, 58], [3, 5], 17, 7)
		  ]

rounds = 10000
for i in range(rounds):
	for p in players:
		p.play()
	#print(i)

tosses = [p.inspect for p in players]
tosses.sort()
part1_answer = tosses[-1] * tosses[-2]
print(part1_answer)