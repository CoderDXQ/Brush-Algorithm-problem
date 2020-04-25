#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int s;
    Node* next;
};

void dayin(Node* list1,Node* list2)
{
    Node* n1=list1;
    Node* n2=list2;

    while(n1!=nullptr && n2!=nullptr)
    {
        if(n1->s<n2->s)
        {
            n1=n1->next;
        }
        else if(n1->s==n2->s)
        {
            cout<<n1->s<<' ';
            n1=n1->next;
            n2=n2->next;
        }
        else 
        {
            n2=n2->next;
        }
    }
}


int main()
{
    Node* list1=new(Node);
    list1->s=-1;
    list1->next=nullptr;

    Node* head1=list1;
    for(int i=0;i<=4;i++)
    {
        int k;
        cin>>k;
        head1->next=new(Node);
        head1=head1->next;
        head1->s=k;
        head1->next=nullptr;
    }

    Node* list2=new(Node);
    list2->s=-4;
    list2->next=nullptr;

    Node* head2=list2;
    for(int i=0;i<=4;i++)
    {
        int k;
        cin>>k;
        head2->next=new(Node);
        head2=head2->next;
        head2->s=k;
        head2->next=nullptr;
    }
    
    cout<<"**********"<<endl;

    dayin(list1,list2);

    return 0;
}
