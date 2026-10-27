class Twitter {
public:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {  
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;
        following[userId].insert(userId);

        for(int follows : following[userId]){
            if(!tweets[follows].empty()){
                int i = tweets[follows].size() - 1;

                auto [t, id] = tweets[follows][i];
                pq.push({t, follows, i});
            }
        }

        vector<int> feed;

        while(!pq.empty() && feed.size() < 10){
            auto[t, follows, i] = pq.top();
            pq.pop();

            feed.push_back(tweets[follows][i].second);
            if(i > 0){
                int prevIdx = i - 1;
                auto [time, prevId] = tweets[follows][prevIdx];
                pq.push({time, follows, prevIdx}); 
            }

        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */