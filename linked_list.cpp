#include<iostream>



using namespace std;

struct node
{
    int data;
    node *next;
};



class linked_list{
public:
    node *head,*tail;


    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
};
