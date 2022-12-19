#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *TakeInput_better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data); //dynamically created
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            //or tail=newNode
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int length(Node *head) {
  
    if(head==NULL)
        return 0;
    
    return 1+ length(head->next);
    
}
Node* removeduplicates(node* head,int n)
{
    //write your code here
    Node *p=head;
    Node *q=head->next;
    if(head->next==NULL)
    return head;

    while(q!=NULL){
        if(q->data==p->data)
        {
           q=q->next;
        }
        else{
            p->next=q;
            q=q->next;
            p=p->next;
        }

    }

    p->next=q;   
    return head;
    
}

int main()
{
   int n;
    Node *head = TakeInput_better();
    print(head);
    cout<<"enter number of element from last to append"<<endl;
    cin>>n;
    head=AppendLastNToFirst(head, n);
    print(head);
}