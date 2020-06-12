#include<iostream>
#include<cstring>
#include"hashtable.h"
using namespace std;
template<typename T>
class node
{
public:
    T value;
    string key;
    node<T>* next;
    node(string k,T v)
    {
        key=k;
        value=v;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class hashtable
{
    int cs;
    int ts;
    node<T>**bucket;
    int hashfn(string key)
    {
        int ans=0;
        int p=1;
        for(int i=0;i<key.length();i++)
        {
            ans=ans + key[i]*p;
            p=p*37;
            ans=ans%ts;
            p=p%ts;
        }
        return ans;
    }
    void rehash()
    {
        node<T>**oldbucket=bucket;
        int oldts=ts;
         ts=ts*2;
        bucket=new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            bucket[i]=NULL;
        }
        cs=0;
        for(int i=0;i<oldts;i++)
        {
            node<T>*temp=oldbucket[i];
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    insert(temp->key,temp->value);
                    temp=temp->next;
                }
                delete oldbucket[i];
            }
        }
        delete [] oldbucket;
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
    int  insert(string key,T value)
    {
        int i = hashfn(key);
        node<T>*n= new node<T>(key,value);
        n->next=bucket[i];
        bucket[i]=n;
        cs++;
        float threshhold=(1.0)*cs/ts;
        if(threshhold>=0.7)
        {
          cout<<"load factor is "<<threshhold<<endl;
          rehash();
        }
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T>*temp=bucket[i];
            cout<<"bucket"<<i<<" ->";
            while(temp!=NULL)
            {
                cout<<temp->key<<"-"<<temp->value<<" || ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string key)
    {
        int i = hashfn(key);
        node<T>*temp=bucket[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &temp->value;
            }
        }
        return NULL;
    }
};
int main()
{
    hashtable<int>h(7);
    h.insert("mango",120);
    h.insert("apple",160);
    h.insert("banana",20);
    h.insert("kiwi",75);
    h.insert("pepsi",25);
    //h.insert("corn",63);
    h.print();
    int *s=h.search("apple");
    if(s==NULL)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<*s<<endl;
    }

    cout<<endl;

}
