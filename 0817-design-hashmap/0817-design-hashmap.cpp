class MyHashMap
{
    public:
        int n;
    vector<int> arr;
    MyHashMap() {
        n=1000001;
        arr.resize(n,-1);
    }

    void put(int key, int value)
    {
        arr[key] = value;
    }

    int get(int key)
    {
        int ans = arr[key];
        return ans;
    }

    void remove(int key)
    {
        arr[key] = -1;
    }
};

/**
 *Your MyHashMap object will be instantiated and called as such:
 *MyHashMap* obj = new MyHashMap();
 *obj->put(key,value);
 *int param_2 = obj->get(key);
 *obj->remove(key);
 */