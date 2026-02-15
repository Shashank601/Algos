
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode* temp = head;

        int cnt = 0;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        int partSz = cnt/k;
        int left = cnt%k;


        temp = head;

        for (int i = 0; i < k; i++) {
            ListNode* currHead = temp;
            

            int nodeCnt = partSz + (left > 0 ? 1 : 0);
            ListNode* lst = nullptr;
            while (temp && nodeCnt--) {
                lst = temp;
                temp = temp->next;
            }
            if (lst) lst->next = nullptr;

            ans[i] = currHead;
            left--;
        }

        return ans;
    }
};


chatgpt :

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);

        // Count nodes
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        int base = n / k;
        int extra = n % k;

        curr = head;

        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;

            int size = base + (i < extra ? 1 : 0);

            // Move to last node of this part
            for (int j = 1; j < size; j++)
                curr = curr->next;

            // Break the list
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return result;
    }
};

close hi hai mera code...
i am getting smarter 
