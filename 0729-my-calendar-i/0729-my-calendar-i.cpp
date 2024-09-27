class MyCalendar {
    vector<pair<int, int>> intervals;
    bool isoverlap(int s1,int e1,int s2,int e2){
        return (max(s1,s2) < min(e1,e2));
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:intervals){
            if(isoverlap(it.first,it.second,start,end)){
                return false;
            }
        }
        intervals.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */