#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class Queue{
    Node *front,*rear;
public:
    Queue();
    void enqueue();
    void dequeue();
    void displayQueue();
    void peek();
};

Queue::Queue(){
    front=rear=NULL;
}

void Queue:: enqueue(){
        int element;
        cout<<"Enter element to be entered into queue:";
        cin>>element;
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = NULL;
        if(front==NULL){
            front=rear = newNode;
        }
        else{
            rear->next = newNode;
            rear=newNode;
        }
}

void Queue:: dequeue(){
        if(front==NULL){
            cout<<"UnderFlow.. No elements to delete"<<endl;
        }
        else{
            Node *temp;
            temp = front;
            front=front->next;
            free(temp);
            if(front==NULL){
                front=rear=NULL;
            }
        }
}

void Queue::displayQueue(){
    for(Node *temp=front;temp!=NULL;temp=temp->next){
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

void Queue:: peek(){
    if(front==NULL){
        return;
    }
    cout<<front->data<<" is at peek"<<endl;
}

int main(){
    int choice;
    Queue newQueue;
    while(1){
        cout<<"1.enqueue\n2.dequeue\n3.peek\n:";
        cin>>choice;
        switch(choice){
        case 1:
            newQueue.enqueue();
            newQueue.displayQueue();
            break;
        case 2:
            newQueue.dequeue();
            newQueue.displayQueue();
            break;
        case 3:
            newQueue.peek();
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
