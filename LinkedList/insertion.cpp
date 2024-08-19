#include<iostream>
// #include<vector>
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

    void trav(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* insertAtHead(Node* head, int val){
        // if(head == NULL) return head;
        // Node* temp = head;
        Node* var = new Node(val, head);
        head = var;
        return head;

    }

    Node* insertAtTail(Node* head, int val){
        Node* var = new Node(val);
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = var;
        return head;
    }

    Node* insertAtIndex(Node* head, int val, int index){
        if(head == NULL){
            if(index == 1) return new Node(val);
            else return head;
        }
        if(index == 1){
            return new Node(val, head);
        }
        int cnt = 0;
        Node* trav = head;
        while(trav != NULL){
            cnt++;
            if(cnt == index - 1){
                Node* temp = new Node(val);
                temp->next = trav->next;
                trav->next = temp;
                break;
            }
            trav = trav->next;
        }
        return head;
    }

    Node* insertBeforEle(Node* head, int val, int ele){
        if(head == NULL) return head;
        if(head->data == ele) return new Node(val, head);
        Node* trav = head;
        while(trav->next != NULL){
            if(trav->next->data == ele){
                Node* temp = new Node(val, trav->next);
                trav->next = temp;
                break;
            }
            trav = trav->next;
        }
        return head;
    }


};
int main(){
    int arr[] = {2, 5, 9, 12};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->trav(head);
    // head = head->insertAtHead(head, 7);
    // head = head->insertAtTail(head, 18);
    // head = head->insertAtIndex(head, 1, 3);
    head = head->insertBeforEle(head, 7, 9);
    head->trav(head);
}