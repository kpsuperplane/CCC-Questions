# See C++ Version for details on how to solve

cases = int(raw_input())

dp = [[0] * 60001 for j in range(0, 501)]
scores = [0] * 60001
sums = [0] * 60001

for iasd in range(0, cases):
	args = map(int, raw_input().split())
	pins = args[0]
	balls = args[1]
	width = args[2]
	arrW = (pins + width + 2)
	for i in range(0, arrW):
		dp[0][i] = 0
		scores[i] = 0
		sums[i] = 0
	for i in range(width, pins + width):
		scores[i] = int(raw_input())
		sums[i] = sum(scores[i-width+1:i+1])

	for row in range(1, balls+1):
		for pin in range(width, pins + width):
			dp[row][pin] = max(sums[pin] + dp[row-1][pin-width], dp[row][pin-1])
			
	print max(dp[balls])