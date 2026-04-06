from collections import defaultdict
"""
deleting from dict
    map.pop(key, None)

clearing
    map.clear()

deleting from set
    set.discard(var) # removes if present, does nothing otherwise

modofying st while itereating:
for x in list(s):
    s.remove(x)
"""

class Twitter:

    def __init__(self):
        self.following = defaultdict(set) # dict[int, set of userid]
        self.tweets = defaultdict(list) # dict[int, list of tweets (timestamp, tweetid)]
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []
        h = [] # heap of (time, tweetId, followeeId, idx_of_tweet in that list)
        followees = self.following[userId] # get set of following
        followees.add(userId) # add yourself so you see your own tweets

        for followee in followees:
            if self.tweets[followee]: # if followee has tweets
                idx = len(self.tweets[followee]) - 1 # idx of the latest tweet for this followee
                t, tid = self.tweets[followee][idx] # get their latest tweet
                heapq.heappush(h, (-t, tid, followee, idx))
        
        while h and len(res) < 10:
            _, tid, followee, idx = h[0]
            heapq.heappop(h)

            res.append(tid)

            prev_idx = idx - 1
            if self.tweets[followee] and prev_idx >= 0:
                t, tid, = self.tweets[followee][prev_idx]
                heapq.heappush(h, (-t, tid, followee, prev_idx))

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)
"""
user ids
tweet ids

userid -> set of following
userid -> list of tweets (timestamp, tweetid)

get news feed

for the given user, get the set of following
    for each followee:
        if they have tweets:
            push the most recent one

res = [] # lsit of tweet ids

while h and len(res) <= 10:
    append most recent tweetid onto res. 
    
    idx_of_next recent = idx - 1
    if this user has more tweets and idx_of_next >= 0
        push the second most recent tweet onto heap 


"""