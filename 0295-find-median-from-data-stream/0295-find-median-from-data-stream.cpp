class MedianFinder {
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    int cnt;
public:
    MedianFinder() {
        cnt=0;
    }
    
    void addNum(int num) {
        mini.push(num);
        maxi.push(mini.top());
        mini.pop();
        if(maxi.size()>mini.size()){
            mini.push(maxi.top());
            maxi.pop();
        }
        cnt++;
    }
    
    double findMedian() {
        if(cnt&1){
            return mini.top();
        }
        else{
            return (double)(maxi.top()+mini.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */