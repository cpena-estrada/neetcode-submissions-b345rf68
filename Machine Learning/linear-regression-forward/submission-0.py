import numpy as np
from numpy.typing import NDArray


# Helpful functions:
# https://numpy.org/doc/stable/reference/generated/numpy.matmul.html
# https://numpy.org/doc/stable/reference/generated/numpy.mean.html
# https://numpy.org/doc/stable/reference/generated/numpy.square.html

class Solution:
    
    def get_model_prediction(self, X: NDArray[np.float64], weights: NDArray[np.float64]) -> NDArray[np.float64]:
        # X is an Nx3 NumPy array
        # weights is a 3x1 NumPy array
        # HINT: np.matmul() will be useful
        # return np.round(your_answer, 5)

        # multiply X by weights to get prediction
        pred = np.matmul(X, weights)
        return np.round(pred, 5)


    def get_error(self, model_prediction: NDArray[np.float64], ground_truth: NDArray[np.float64]) -> float:
        # model_prediction is an Nx1 NumPy array
        # ground_truth is an Nx1 NumPy array
        # HINT: np.mean(), np.square() will be useful
        # return round(your_answer, 5)

        # calculate squre error for all, add them divide by N

        difference = model_prediction - ground_truth # performs operation on each pair of indeces
        squared_diff = np.square(difference)
        mse = np.mean(squared_diff)
        return round(mse, 5) # its just a number, not a numpy array so just do round(), notnp.round()




"""
DONT USE FOR LOOPS, NUMPY OPERATIONS AVOID THAT

WRONG

        summation = 0.0
        for pred, truth in zip(model_prediction, ground_truth):
            summation += np.square(pred - truth)

        error = summation / len(ground_truth),
        
        return round(error, 5)
"""



