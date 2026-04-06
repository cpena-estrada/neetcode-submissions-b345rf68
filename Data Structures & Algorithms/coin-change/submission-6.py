class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # let dfs(remaining) return min number of coins needed to make sum 'remaining'

        cache = {} # ammount : min num of coins needed

        def dfs(remaining):
            if remaining in cache:
                return cache[remaining]
            
            if remaining == 0: 
                return 0 # you need 0 coins to make amount 0
            
            res = 1e9 # init answer for this state

            for coin in coins:
                if remaining - coin >= 0:
                    res = min(res, 1 + dfs(remaining - coin))
                    cache[remaining] = res
                    # if you choose curr coin, you spend 1 coin now
                    # you still need to solve the subproblem remaining-coin
            
            return res

        coins_needed = dfs(amount)

        return coins_needed if coins_needed != 1e9 else -1

        
        
"""

DFS WITH A GLOBAL RES (TLE's):

this cannot be chached because the dfs functino does not return anything, so you cant cahce anything

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        self.res = float('inf')

        def dfs(idx, remaining, count):
            if remaining == 0:
                self.res = min(self.res, count)
                return

            if idx >= len(coins):
                return
            
            if remaining - coins[idx] >= 0: # if can you take with this denom, take as many as possible 
                dfs(idx, remaining - coins[idx], count + 1)
            
            dfs(idx + 1, remaining, count) # always explore path to not take

        #for i in range(len(coins)): 
        # dont need a for loop because you indirectly try to start and to skip from every idx thanks to the 2 recursive calls
        dfs(0, amount, 0)

        return self.res if self.res != float('inf') else - 1


if you still have remaining, keep taking

canonical for a regualr denominations, but fails to the testcases where denominations arent nice

iterate over coins in reverse order (try higher denoms first)
    - try as many coins of this demonimation until you cant

        if amount == 0: return 0 # 0 coins needed

        coins.sort(reverse= True)
        remaining = amount
        count = 0 # number of coins taken

        print(coins)

        for coin in coins:
            to_use = remaining // coin

            if to_use: # if it divided nicely
                count += to_use
                remaining -= coin * to_use

            # else skip this denom and dont update anything

        return count if remaining == 0 else -1
"""