class Solution:
    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        # initial guess
        x = init 

        for i in range(iterations):
            gradient_derivative = 2 * x # derivative of x^2 is 2x
            x = x - (gradient_derivative * learning_rate)
        
        return round(x, 5)


"""

Gradient descent is an optimization algorithm used to find the minimum of a function.
Think of it as a ball rolling downhill: 
    the ball always moves in the direction of the negative slope (the gradient)
    until it reaches the lowest point (the minimum).

a derivative tells us how steep the curve is at any point x
(the slope of a func at a specific point x)

    f(x) = x^2  -> f'(x) = 2x 

So,

    The Derivative = Slope = Direction

    - If slope > 0 (positive), the function is increasing -> the minimum is to the left.
    - If slope < 0 (negative), the function is decreasing -> the minimum is to the right.


so do negative gradient/derivative baceause we want to go down (minimize)
    
    positive slope?
        x = x - ( +f'(x) * lr)     goes left/subtract from x
    
    negative slope?
        x = x - ( -f'(x) * lr)  goes right/ add to x

"""