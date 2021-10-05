/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)
            return false;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==nullptr){
                delete fast,slow;
                return false;
            }
            else if(fast->next==slow->next){
                delete fast,slow;
                return true;
        }
        }
        delete fast,slow;
        return false;
    }
};
