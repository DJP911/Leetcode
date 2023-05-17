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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        stack<int> s;
        while(temp){
            s.push(temp->val);
            temp = temp->next;
        }
        int maxValue = 0 ;
        while(s.size()/2){
            maxValue = max(maxValue,s.top()+head->val);
            head = head->next;
            s.pop();
        }
        return maxValue;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast=head,*slow=head;
        int maxSum=0;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *next=NULL,*prev=NULL;
        while(slow!=NULL){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }

        while(prev){
            maxSum=max(maxSum,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return maxSum;
    }
};
