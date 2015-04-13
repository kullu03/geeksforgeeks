# using divide and conquer approach

def minCoins(coins,amount):
	mysol = [0]*len(coins)
	finalsol = [-1]*len(coins)
	if amount == 0:
		return 0

	for i in range(0,len(coins)-1):
		if coins[i] <= amount:
			mysol[i] = minCoins(coins,amount-coins[i])
			finalsol[i] = mysol[i]

	#print finalsol
	return finalsol
			

m = minCoins([1, 5, 10, 25],35)
print m
