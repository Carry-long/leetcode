#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int tag = 0;
    ListNode *head = new ListNode(0);
    ListNode *root = head;

    while(l1 != nullptr || l2 != nullptr){
        int sum = 0;
        if (l1 != nullptr) sum += l1->val;
        if (l2 != nullptr) sum += l2->val;
        sum += tag;
        if (sum>9) {
            sum = sum % 10;
            tag = 1;
        } else {
            tag = 0;
        }

        ListNode *node = new ListNode(sum);
        head -> next = node;
        head = node;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;

    }

    if(tag != 0) {
        ListNode *node = new ListNode(tag);
        head -> next = node;
    }
    return root->next;
}

ListNode* addTwoNumbers2 (ListNode* l1, ListNode* l2) {
    int tag = 0;
    ListNode *head = new ListNode(0);
    ListNode *root = head;
    while(l1 != nullptr && l2 != nullptr){
        int sum = l1->val + l2->val + tag;
        if (sum>9) {
            sum = sum - 10;
            tag = 1;
        } else {
            tag = 0;
        }

        ListNode *node = new ListNode(sum);
        head -> next = node;
        head = node;
        l2 = l2->next;
        l1 = l1->next;

    }
    while(l1 != nullptr){
        int tmp = tag + l1->val;
        if (tmp>9) {
            tmp = tmp - 10;
            tag = 1;
        } else {
            tag = 0;
        }

        ListNode *node = new ListNode(tmp);
        head -> next = node;
        head = node;
        l1 = l1->next;
    }
    while(l2 != nullptr){
        int tmp = tag + l2->val;
        if (tmp>9) {
            tmp = tmp - 10;
            tag = 1;
        } else {
            tag = 0;
        }
        ListNode *node = new ListNode(tmp);
        head -> next = node;
        head = node;
        l2 = l2->next;
    }
    if(tag != 0) {
        ListNode *node = new ListNode(tag);
        head -> next = node;
    }
    return root->next;
}

int main() {

    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(8);
//    ListNode* c = new ListNode(3);
    a->next = b;
//    b->next = c;
    b->next = nullptr;

    ListNode* d = new ListNode(0);
//    ListNode* e = new ListNode(6);
//    ListNode* f = new ListNode(4);
//    d->next = e;
//    e->next = f;
    d->next = nullptr;

    ListNode* res = addTwoNumbers(a,d);
    while(res != nullptr){
        cout<< res->val<<endl;
        res = res->next;
    }
    return 0;
}

