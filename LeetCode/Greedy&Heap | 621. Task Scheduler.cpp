class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
   
        vector<int> freq(26);
        for (auto ch : tasks) freq[ch - 'A']++;   <--- not 'a'

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            pq.push(freq[i]);
        }
        queue<pair<int,int>> cooldown;

        
        int timer = 0;
        while (!pq.empty() || !cooldown.empty()) {
            timer++;
            if (!pq.empty()) {                <--- check again  due to 'OR' in loop condn we are not sure whether pq have element, on empty pq .top is will giive errror
                int f = pq.top(); pq.pop();          <---- max handled first  so we can decrese idle time

                if (f > 1) {   <--- if f == 0 => its done
                    cooldown.push({f - 1, timer + n});    <--- key to get next running time just + n
                }
            }
            
            if (!cooldown.empty() && cooldown.front().second == timer) {   <---- reneter pq if it have completed its sentence
                pq.push(cooldown.front().first); cooldown.pop();
            }
        }
        return timer;

    }
};
