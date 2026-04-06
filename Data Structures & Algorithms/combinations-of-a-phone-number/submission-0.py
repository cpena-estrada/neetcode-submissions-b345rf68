class Solution:
    mapping = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits: 
            return []
        path, res = [], []

        def dfs(idx: int):

            if len(path) == len(digits):
                res.append(''.join(path.copy()))
                return

            if idx >= len(digits):
                return
            
            digit = digits[idx]
            for ch in self.mapping[digit]:
                path.append(ch)
                dfs(idx + 1)
                path.pop()

        dfs(0)

        return res

"""
23

[a]

def dfs():

    if len(path) == len(digits):
        res.append(path.copy)

    for digit in digits:
        for ch in mapping[digit]:
          path.append(a)
          dfs()
          path.pop()

abc

"""