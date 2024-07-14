class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
public:
unordered_map<int,Node*> mp;
int n;
Node* anshead=new Node(-1,-1);
Node* anstail=new Node(-1,-1);
    LRUCache(int capacity) {
        anshead->next=anstail;
        anstail->prev=anshead;
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int value=mp[key]->val;
        mp[key]->prev->next=mp[key]->next;
        mp[key]->next->prev=mp[key]->prev;
        mp[key]->next=NULL;
        mp[key]->prev=NULL;
        mp.erase(key);
        Node* newnode=new Node(key,value);
        newnode->next=anshead->next;
        newnode->prev=anshead;
        anshead->next->prev=newnode;
        anshead->next=newnode;
        mp[key]=anshead->next;
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->prev->next=mp[key]->next;
            mp[key]->next->prev=mp[key]->prev;
            mp[key]->next=NULL;
            mp[key]->prev=NULL;
            mp.erase(key);
        }
        else if(mp.size()==n){
            Node* f=anstail->prev;
            anstail->prev->prev->next=anstail;
            anstail->prev=anstail->prev->prev;
            f->next=NULL;
            f->prev=NULL;
            mp.erase(f->key);
        }
        Node* newnode=new Node(key,value);
        newnode->next=anshead->next;
        newnode->prev=anshead;
        anshead->next->prev=newnode;
        anshead->next=newnode;
        mp[key]=anshead->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */