/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode* curr = head;
        int length = 0;
        
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        int size = length / k;
        int rem = length % k;
        curr = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; i++) {
            ans[i] = curr;
            int currsize=size;
            if(rem>0)
            {
                 currsize=currsize+1;
                rem--;
            }
            
            for (int j = 0; j < currsize; j++) {
                prev = curr;
                if (curr != nullptr) {
                    curr = curr->next;
                }
            }
            
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
        return ans;
    }
};
