# Advent of code 2022
This is where I'll write down some thoughts regarding the event.
The first days will be smooth sailing, but what I really want to 
record are the much harder days, and my approach to solving the problem.
I'm not writing about *every* day, but rather the ones that stood out to me.

#### Day 1
AOC 2022!

#### Day 5
Pretty interesting, parsing the drawing and the instructions.
Interesting problem as well.

#### Day 7
Actually really happy with my solution.
The solution is actually really simple, stripping away the unessecary 
parts and mapping directory sizes and the directories themselves using hashmaps stacks i
nstead of recursively building a tree.

#### Day 10
Part 2's output was actually really cool. 
Wonder how Eric generates inputs for all the contestants...

#### Day 11
Actually a really interesting optimization problem. Basically, without doing a modulo, the numbers get
huge and that tanks the performance. But if you do a modulo on the products of the divisors, you can 
"clamp" the numbers so that they never exceed a limit, but your end result still stays the same.
Pretty fun!