use vector to keep freq track of curr window
have a maxfreq tracker 

the problem states the window can have at max k intruders

so i will going inc window as long as i have <= k intruders 
when i get more than k intruders i will decrease from left keeping window size const as right will always inc
=> our window never shrink form curr best size

when it will grow? 
=> when some char inflitrate the window and having freq == maxfreq 
=> now if the window maintains that char freq and now that char is immediate next to window 
mean maxFreq will finlly update and so window len (when max freq inc <--> win len also incre they are interdependent)

=> but if immediate next is not that char so its a potential intruder so if it dont affect that char freq in window(means it just taking place of some other intruder) 
then we still have a chance to grow as soon as that char overtake old_maxFreq;

=> everytime you attempt: justify stale max, single shrink => only then submit


best input : [99 A`s, 99 Rand(), 100B`s, 1 Rand(), 1B`s] and  k is 2
                          ^ non a`s and b`s    


class Solution {
public:
    int characterReplacement(string s, int k) {
        // i guess we can tolerate at max k intruders in the window

        // i will attempt O(n) tc

        // key is to know the max freq

        // i will grow my window as long as i have <= k intruders

        // if my window exceed k mark i will start sliding 

        // i will go with the variant in which we dont shrink from curr best

        // why not shrink => no point, we need better next window it cant be smaller than curr best
        
        // notice now curr best window has some char with maxFreq and <= k intruders

        // so new best window is going to have some char with > maxFreq and <= k intruders 
        // => if from curr best, no new window with same size have some char == max FREQ then window will never expand/grow
        // => growth requirement is have  appearance of someChar == maxFreq 
        // and after the new char has inflitrated the curr window maxFreq times

        // so immediate-next/new char must not increase intruder count  => very vague => so now curr window have maxFreq times some char again => now next char must inc count of that 'some' char or throw one intruder out, and enter in window  => only if you need better window  

        // only then window going to have better length and <= k intruder => expansion possible

        // reminder: everytime you attempt: justify stale max, single shrink only then submit

        // once window have > k intruder => window shrink from left but simulaneously grow from right so size never decrease

        // also once the window have == k intruder then all next windows going to have == k intruder 
        int n = s.length();
        vector<int> freq(26);

        int maxFreq = 0;
        int ansLen = 0;
        int l = 0;
        int r = 0;

        while (r < n) {
            int win = r - l + 1;
            maxFreq = max(maxFreq, ++freq[s[r] - 'A']); //post increment is wron it will lag maxFReq premature shrink better window
            r++;
            if (win - maxFreq <= k) { //grow
                ansLen = max(ansLen, win);
            } else { //no while loop just single shrink
                freq[s[l] - 'A']--;
                l++;
            }
        }
        return ansLen;
    }
};
