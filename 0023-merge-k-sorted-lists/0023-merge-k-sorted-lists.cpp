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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;

        for(ListNode* ele : lists){
            ListNode* temp = ele;
            while(temp != nullptr){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size()==0)return nullptr;
        ListNode* res = new ListNode(ans[0]);
        
        ListNode* temp = res;
        for(int i =1; i < ans.size(); i++){
            res->next = new ListNode(ans[i]);
            res = res->next;
        }
        return temp;
    }
};