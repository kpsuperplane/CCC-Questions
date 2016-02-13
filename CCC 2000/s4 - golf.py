### IDEA:
### dp[n] represents the least number of strokes to get to distance 'n'
### Runs in O(dist * club) time

clubs = []

dist = int(raw_input()) #Get the distance

dp = [-1] * 5381 #Accomodate for club overflow

for i in range(0, int(raw_input())): #Get all the club values
	clubs.append(int(raw_input()))

dp[0] = 0 #we start off at the beginning

for i in range(0, dist-1): #loop through the entire distance
	if dp[i] != -1: #check if it is possible to hit from this place. 
	# ^ Can be optimized by keeping record of the next closest dest
		for club in clubs: # loop through each club
			next = i + club #find where this club would land the ball
			if dp[next] == -1 or dp[next] > dp[i] + 1: #Check if this is more optimal 
				dp[next] = dp[i] + 1 #update

if dp[dist] != -1:
	print "Roberta wins in", dp[dist], "strokes."
else:
	print "Roberta acknowledges defeat."