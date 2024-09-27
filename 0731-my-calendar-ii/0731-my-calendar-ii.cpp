class MyCalendarTwo {
    vector<pair<int,int>> overallbooking;
    vector<pair<int,int>> doublebooking;
    bool checkoverlap(int s1,int e1,int s2,int e2){
        return (max(s1,s2) < min(e1,e2));
    }
    pair<int,int> findoverlap(int s1,int e1,int s2,int e2){
        return {max(s1,s2),min(e1,e2)};
    }
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:doublebooking){
            if(checkoverlap(it.first,it.second,start,end)){
                return false;
            }
        }
        for(auto it:overallbooking){
            if(checkoverlap(it.first,it.second,start,end)){
                doublebooking.push_back(findoverlap(it.first,it.second,start,end));
            }
        }
        overallbooking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */