class Twitter {
private:
    unordered_map<int, unordered_set<int>> user_followed; //{id, {set} }
    vector<tuple<int, int, int>> tweets; // user, tweet id, time
    int time;
public:
    Twitter() {
        tweets = {};
        time = 0;

        for (int i = 1; i <= 100; ++i) {
            user_followed[i] = {};
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.emplace_back(userId, tweetId, time); //tweets.push_back(make_tuple(userID, tweetID, time));
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> tweet_time = {};
        for (const auto& [uid, tid, t] : tweets) {
            if (uid == userId || user_followed[userId].count(uid)) {
                tweet_time.emplace_back(tid, t);
            }
        }

        sort(tweet_time.begin(), tweet_time.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> res; //tweetids
        int len = min(10, int(tweet_time.size()));

        for (int i = 0; i < len; i++) {
            res.emplace_back(tweet_time[i].first);
        }

        // int k = 0;
        // for (const auto& pair : tweet_time) { // get 10 first tweets
        //     if (k == 10) { break; }
        //     res.emplace_back(pair.first);
        //     k++;
        // }
        return res;
    }

    void follow(int followerId, int followeeId) {
        user_followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_followed[followerId].erase(followeeId);
    }
};


    /*

    vector of tweets
    vector<(user_id, tweet_id, time)>

    iterate over tweet vector
    append tweets of user ids to res
    sort in descedning order 
    return it

    */
