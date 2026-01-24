acc to chatgpt analy my approcah is sloppy 

but lpgically my  counter using aapproch is right, and not accidental

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        
        int h = 0;

        // 0 1 3 5 6


        for (int i = n - 1; i >= 0; i--) {
            int len = n - i;
            if (len <= citations[i]) {
                h++;
            }
        }
        return h;

    }
};
