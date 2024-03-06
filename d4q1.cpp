class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*> mpp;
    int size;

    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode){
        newnode->prev=head;
        newnode->next=head->next;
        head->next->prev=newnode;
        head->next=newnode;
    }

    void delnode(node* delnode){
        node* nxt=delnode->next;
        node* pre=delnode->prev;
        pre->next=nxt;
        nxt->prev=pre;
    }

    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node* getnode=mpp[key];
            int value=getnode->val;
            mpp.erase(key);
            delnode(getnode);
            addnode(getnode);
            mpp[key]=head->next;
            return value;
        }    
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* foundnode=mpp[key];
            mpp.erase(key);
            delnode(foundnode);
        }
        if(size==mpp.size()){
            mpp.erase(tail->prev->key);
            delnode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
