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
   int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL || head==NULL){
            return head;
        }
        ListNode* temp = head;
        vector<int> add;
        while (temp->next != NULL) {
            add.push_back(gcd(temp->val, temp->next->val));
            temp = temp->next;
        }

        temp = head;
        for(int i=0;i<add.size();i++){
            ListNode* addnew = new ListNode(add[i]);
              ListNode* nextofcurr = temp->next;
            temp->next = addnew;
              addnew->next = nextofcurr;
            temp = addnew->next;
        }
        return head;
    }
};