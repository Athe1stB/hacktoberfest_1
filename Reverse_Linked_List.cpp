class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    { 
        Node* prev= NULL;
        Node* curr= head;
        Node* nextptr=NULL;
         while(curr!=NULL){
             nextptr=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nextptr;
         }
        head= prev;
        
        // return head of reversed list
        return head;
    }
    
};
