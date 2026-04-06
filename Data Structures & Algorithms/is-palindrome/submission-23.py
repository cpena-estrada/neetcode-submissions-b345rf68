class Solution:
    def is_alphanumeric(self, c: str) -> bool:
        return (ord(c) >= ord('a') and ord(c) <= ord('z') or
                ord(c) >= ord('A') and ord(c) <= ord('Z') or
                ord(c) >= ord('0') and ord(c) <= ord('9'))
                
    def isPalindrome(self, s: str) -> bool:
        if len(s) == 1:
            return True

        left, right = 0, len(s) - 1

        while left < right:
            if not self.is_alphanumeric(s[left]):
                left += 1
                continue

            if not self.is_alphanumeric(s[right]):
                right -= 1
                continue

            if s[left].lower() != s[right].lower():
                return False
            
            left += 1
            right -= 1
        
        return True
