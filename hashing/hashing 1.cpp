#include<iostream>
#include<cstring>
#include"hashtable.h";
using namespace std;

template<typename T>
class node
{
public:
    string key;
    T value;
    node<T>* next;
    node(string k,T v)
    {
        key=k;
        value=v;
    }
};
template<typename T>
class hashtable
{
    int cs;
    int ts;
    node<T>** bucket;
    int hashfn(string key)
    {
        int ans=0;
        int L=key.length();
        int p=1;
        for(int i=0;i<L;i++)
        {
            ans+=key[L-i-1]*p;
            p=p*37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }
    public:
    hashtable(int ds=7)
    {
        cs=0;
        ts=ds;
       bucket=new node<T>*[ts];
       for(int i=0;i<ts;i++)
       {
           bucket[i]=NULL;
       }
    }
    void insert(string key,T value)
    {
        int i=hashfn(key);
        node<T>* n=new node<T>(key,value);
        n->next=bucket[i];
        bucket[i]=n;
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T>*temp=bucket[i];
            cout<<"bucket "<<i<<"->";
            while(temp!=NULL)
            {
                cout<<temp->key<<" ,"<<temp->value<<"||";
                temp=temp->next;
            }
          cout<<endl;
        }
    }
    T* search(string key)
    {
        int i=hashfn(key);
        node<T>*temp=bucket[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;
    }
};
int main()
{
    hashtable<int>h(11);
    h.insert("mango",100);
    h.insert("banana",170);
    h.insert("apple",140);
    h.insert("guava",130);
    h.insert("chiku",150);
    h.print();

    string f;
    cin>>f;
    int *price=h.search(f);
    if(price==NULL)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"price of this is "<<*price<<endl;
    }
    }
