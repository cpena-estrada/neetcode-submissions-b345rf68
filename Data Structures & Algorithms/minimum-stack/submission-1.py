class MinStack:

    def __init__(self):
        self.stk = []
        self.minimums = []

    def push(self, val: int) -> None:
        self.stk.append(val)

        # if its the very first append (aka minimumns is empty)
        if not self.minimums:
            self.minimums.append(val)
        else:
            self.minimums.append(min(val, self.minimums[-1]))
        

    def pop(self) -> None:
        self.stk.pop()
        self.minimums.pop()

    def top(self) -> int:
        return self.stk[-1]

    def getMin(self) -> int:
        return self.minimums[-1]
