attempt 3 (try std way too as my approach is very hacky)

try somwday..

 [odd->next = even->next;
  odd = odd->next;

  even->next = odd->next;
  even = even->next;] 




attempt 2
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* ans = head;
        
        ListNode* h1 = head;
        
        head = head->next;
        ListNode* pinH2 = head;
        ListNode* h2 = head;

        bool toggle = true;

        head = head->next;
        while (head) {
            if (toggle) {
                h1->next = head;
                h1 = h1->next;
                head = head->next;
            } else {
                h2->next = head;
                h2 = h2->next;
                head = head->next;

            }

           if (!head) h2->next = nullptr;

            toggle = !toggle;

        }

        h1->next = pinH2;

        return ans;


    }
};




attempt1

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* ans = head;

        ListNode* h1 = head;
        head = head->next;

        ListNode* h2 = head;
        ListNode* pinned = head;
        
        head = head ? head->next : nullptr;

        bool flag = true;

        while (head) {
            if (flag) {   
                h1->next = head;
                h1 = h1->next;
                head = head->next;
            } else {
                h2->next = head;
                h2 = h2->next;
                head = head->next;
            }
            // if (!head) h2->next = nullptr;
            // a ques for you so why i got address santizer instead of tle if last node pont back to some node  in the middle of structure
            flag = !flag;
        }

        h1->next = pinned;

        return ans;
    }
};
