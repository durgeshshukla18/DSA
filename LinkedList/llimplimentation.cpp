#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }




};
int main(){
    Node* head = new Node(1);
    cout<<head->data<<endl;
    Node* a = new Node(2, head);
    cout<<head->next<<endl;
    cout<<a->data<<endl;
    cout<<a->next<<endl;
    cout<<addressof(head)<<endl;
    cout<<addressof(a)<<endl;
}