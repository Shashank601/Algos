class Twitter {
public:
    
    users: []
    
    each user can follow other

    and can unfollow other

    timer = 0;

    user: [_, _, _, ...]
    unordered_map<int, unordered_set<int>> userFollowing

    unordered_map<int, vector<pair<int,time(int)>>> userTweets


    int -> [int, int, int, ...]
             |    |    |
             o    o   empty
                  o
                  o



    i have list of tweets

    [Most recent                     least recent]
    [Most recent             least recent]
    [Most recent                                  least recent]

    so
    {time, id} ..
    {time, id} ..
    {time, id} ..
   

    
 

    int timer = 0;
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, vector<pair<int,int>>> tweets;
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        
        userId -> 
        friendIds(locates vec) - time(recency) - pos(next cand in vec) -//tweetIds(res units| derivablefrom(pos, friendsid) so removed) 
        state: int int int 

      
        priority_queue<array<int,3>> pq;
        friends[userId].insert(userId);
        //initialization
        for (auto friendId : friends[userId]) {
            int idx = tweets[friendId].size() - 1;
            if (idx >= 0) pq.push({tweets[friendId][idx].first, friendId, idx});
        }
        friends[userId].erase(userId);
       

        while (!pq.empty()) {

            auto states = pq.top(); pq.pop();

            int time = states[0];
            int myId = states[1];
            int idx = states[2];

            res.push_back(tweets[myId][idx].second);
            if (res.size() == 10) 
                return res;
            
            if (idx > 0) {
                pq.push({tweets[myId][idx - 1].first, myId, idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (friends[followerId].count(followeeId)) {
            friends[followerId].erase(followeeId);
        }
    }
};


still bunch of isssues fix them later

eg. getNewsFeed creating user  this violates single responsibility princple 
eg. accessing a key w/o checking it exist => empty vector banjayenege
.
.
