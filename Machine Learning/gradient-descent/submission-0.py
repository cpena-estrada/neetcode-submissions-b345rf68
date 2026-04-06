class Solution:
    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        for i in range(iterations):
            derivative = 2 * init
            init -= derivative * learning_rate; 
        return round(init, 5)



"""

a derivative is the slope of a func at a specific point

    f(x) = x^2  -> f'(x) = 2x 

gradient/derivative points to the direction of greatest incline

the do negative gradient/derivative baceause we want to go down (minimize)

"""