/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
          return head;
      
        if (head -> child  == NULL)
        {
          head -> next = flatten(head -> next);
          return head;
        }
      
      Node* temp = head;
      Node* currnext = temp -> next;
      Node* Ok = flatten(temp -> child);
      
      if (Ok != NULL)
      {
        temp -> next = Ok;
        Ok -> prev = temp;
        temp -> child = NULL;
      }
      
      while (temp -> next != NULL)
        temp = temp -> next;
      
      Ok = flatten(currnext);
      
      if (Ok != NULL)
      {
         temp -> next = Ok;
         Ok -> prev = temp;
      }
     
      return head;
      
    }
};