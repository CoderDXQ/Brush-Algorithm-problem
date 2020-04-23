#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int s;
    Node* next;
};


void dayin(Node* list1,Node* list2)
{
    Node* n1;
    Node* n2;

    n1=list1;
    n2=list2;

    while(n1!=nullptr)
    {
        cout<<n1->s<<' ';


        while(n2!=nullptr)
        {
            while(n1->s==n2->s)
            {
                cout<<n1->s<<' ';
                n1=n1->next;
                n2=n2->next;
            }

         n2=n2->next;

        }

        n2=list2;
        n1=n1->next;
    }

}


int main()
{
    Node* list1=new(Node);
    list1->s=-1;
    list1->next=nullptr;

    Node* head1=list1;
    for(int i=0;i<=5;i++)
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
    for(int i=0;i<=5;i++)
    {
        int k;
        cin>>k;
        head2->next=new(Node);
        head2=head2->next;
        head2->s=k;
        head2->next=nullptr;
    }
    
    
    cout<<"**********"<<endl;
    while(list1!=nullptr)
    {
        cout<<list1->s<<' ';
        list1=list1->next;
    }


    cout<<endl;
    while(list2!=nullptr)
    {
        cout<<list2->s<<' ';
        list2=list2->next;
    }

    dayin(list1,list2);

    return 0;
}


vim
/
rm -rf 

name course  score 


SELECT name FROM table
where AVG(select score from TABLE group by name)>=60;



