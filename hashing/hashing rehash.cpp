#include<iostream>
#include"hashtable.h"
#include<cstring>
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
        int L=key.length();
        for(int i=0;i<L;i++)
        {
            ans=+key[L-i-1]*p;
            p=p*37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }
    void rehash()
    {
        node<T>** oldbucket=bucket;
        int oldts=ts;
        ts=ts*2;
        cs=0;
        bucket=new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            bucket[i]=NULL;
        }
        for(int i=0;i<oldts;i++)
        {
            node<T>* temp=oldbucket[i];
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
    int insert(string key,T value)
    {
        int i=hashfn(key);
        node<T>* n=new node<T>(key,value);
        n->next=bucket[i];
        bucket[i]=n;
        cs++;
        float load_factor=(float)cs/ts;
        if(load_factor>=.7)
        {
            cout<<"load factor is "<<load_factor<<endl;
            rehash();
        }
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T>* temp=bucket[i];
            cout<<"bucket "<<i<<"->";
            while(temp!=NULL)
            {
                cout<<temp->key<<","<<temp->value<<"||";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    hashtable<int>h(7);
    h.insert("mango",100);
    h.insert("banana",170);
    h.insert("apple",140);
    h.insert("guava",130);
    h.insert("chiku",150);
    h.print();
}
