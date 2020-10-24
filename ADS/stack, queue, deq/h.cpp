#include <iostream>

using namespace std;

class Node{ 
public:
    int value;
    Node *next, *prev;
    Node(int val){
        value = val;
        next = prev = NULL;
    }

};

class Deque{
public:
    Node *head=NULL;
    Node *tail=NULL;
    int sz;

    Deque(){
        head = tail = NULL;
        sz = 0;
    }


    void push_back(int val){
        Node* node = new Node(val);
        sz++;
        if(head == NULL){
            head=node; 
            tail=head;
        }
        else{
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
    }
    void push_front(int val){
        Node *node=new Node(val);
        sz++;
        if(head == NULL){
            head=node;
            tail=head;
        }
        else{
            node->next=head;
            head->prev=node;
            head=node;
        }
    }

    void pop_front(){
        if(head != NULL){
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }else{
                tail = NULL;
            }
            sz--;
        }
    }

    int front(){
        if(head != NULL){
            return head->value;
        }
        return -1;
    }

    int size(){
        return sz;
    }
};


 
int main(){
    Deque *first, *second;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int ind;

        if (s == "-"){
            first->pop_front();
        }else if (s == "+"){
            cin >> ind;
            second->push_back(ind);
        }else{
            cin >> ind;
            second->push_front(ind);
        }

        if(first->size() < second->size()){
            int x = second->front();
            second->pop_front();
            first->push_back(x);
        }
    }


}