#include<iostream>
#include<unordered_set>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool hasCycle(ListNode *head){
    std::unordered_set<ListNode*> st;
    ListNode *p = head;
    while(p != nullptr){
        if(st.count(p)){
            return true;
        }
        st.insert(p);
        p = p->next;
    }
    return false;
}


int main(){

}