# Linked Lists

### General Steps:  

### 1. Handling empty cases

For example:

```C++
if(head == nullptr || head->next == nullptr)    return head;
```

### 2. Create dummy node to handle the first node (head) problems

```C++
ListNode* HEAD = new ListNode(0, head);

// ...

ListNode* res = HEAD->next;
delete HEAD;
return res;
```

---

### Head-insert and Tail-insert to create a linked list

give you some values and a dummy head node (HEAD)

### 1. Head-insert

```C++
LisNode* p = nullptr
while(/*... != nullptr*/){
    ListNode* node = new ListNode(val);
    node->next = p;
    p = node;
}
HEAD->next = p;
```

### 2. Tail-insert

```C++
ListNode* p = HEAD;
while(/*... != nullptr*/){
    ListNode* node = new ListNode(val);
    p->next = node;
    p = p->next;
}
```

---

### **Reverse Linked List**: 

- Time complexity: O(n)  
- Space complexity: O(1)

> Question Number: 92, 25

For example:

we have a linked list, head node is 2:  
2->5->8->3->6->9->null

target:  
null<-2<-5<-8<-3<-6<-9

or the same

9->6->3->8->5->2->null

```C++
ListNode* p = head;
ListNode* pre = nullptr;
while(p != nullptr){
    ListNode* nxt = p->next;
    p->next = pre;
    pre = p;
    p = nxt;
}
```

After loop:

- p->nullptr  
- nxt->nullptr  
- pre->9

---

### Fast and Slow pointer

> Question Number: 82

```C++
ListNode* slow = HEAD;
ListNode* fast = HEAD->next;

while(fast != nullptr && slow != nullptr){
    // find duplicate vals
    if(fast->val == fast->next->val){
        while(fast->next != nullptr && fast->val == fast->next->val){
            ListNode* temp = fast;
            fast = fast->next;
            delete temp;
        }
        ListNode* duplicate = fast;
        fast = fast->next;
        delete duplicate;

        slow->next = fast;
    }
    else{
        slow = fast;
        fast = fast->next;
    }
}
```

---

### std::list splice

```C++
std::list<int> lst;
//...   2->5->8->3->6->9

std::list<int>::iterator it;
//...   2->5->8->3->6->9
//               |<-iterator

// if we wanna 3->2->5->8->6->9 (move one node)
lst.splice(lst.begin(), lst, it);

// if we wanna 3->6->9->2->5->8 (move a fragment)
lst.splice(lst.begin(), lst, it, lst.end());

// if we have another list (lst2:7->7->7) and we wanna 2->5->8->3->6->9->7->7->7 (move whole list)
lst.splice(lst.end(), lst2);
```

