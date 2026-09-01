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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==nullptr) return {-1,-1};
        int k=2;
        int sd=-1;
        int ld=-1;
        int md=INT_MAX;
        int last=head->val;
        head=head->next;
        while(head->next!=nullptr){
            if((head->val>last && head->val>head->next->val)||(head->val<last && head->next->val>head->val) ) {
                
               // head=head->next;
            
                if(sd==-1){
                     sd=k;
                     ld=k;}
                     else{
                        
                        md=min(md,k-ld);
                        ld=k;
                     }
            }
            last=head->val;
            head=head->next;
            k++;
        }
        if(md!=INT_MAX) return {md,ld-sd};
        return {-1,-1};
    }
};