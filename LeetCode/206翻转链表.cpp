/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 两种方法：
 * 1. 迭代法：从前向后处理，需要三个指针
 * 2. 递归法：从后向前处理
 * https://zhuanlan.zhihu.com/p/44002914
 */

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // 迭代解法：从前向后翻转
        if (head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* new_head = head->next;
        head->next = NULL;
        ListNode* temp = head;
        ListNode* temp2;
        while (new_head!=NULL){
            temp2 = new_head;
            new_head = new_head->next;
            temp2->next = temp;
            temp = temp2;

        }
        return temp;

        // // 递归解法：从后向前翻转
        // if (head==NULL || head->next==NULL) return head;
        // ListNode* new_head = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return new_head;

        

    }
};