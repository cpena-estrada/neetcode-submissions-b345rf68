class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""

        concat = ""
        for word in strs:
            length = len(word) # int
            concat += str(length) # turn into string
            concat += "#"
            concat += word

        return concat

    def decode(self, s: str) -> List[str]:
        if s == "":
            return []

        res = []

        i = 0
        while (i < len(s)):
            # read the number
            num_string = ""
            while(s[i] != "#"):
                num_string += s[i]
                i += 1
            
            num = int(num_string)
            i += 1 # moves i over from # to beggining of word

            # read the x next characters from s
            curr_word = ""
            for j in range(num):
                curr_word += s[i]
                i += 1

            # a tthis point, i is at beggingig of next number

            # append what you read 
            res.append(curr_word)

        return res


"""
encode:
    we can create an empty string variable and concat to it 
           i
       j                    for loo but read [i]
    40#neet42#code4#love3#you


    ####


"""