class MyCalendarTwo {
    vector<pair<int, int>> single;
    vector<pair<int, int>> double_booked;
public:
     
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end){
        for(const auto & [s,e] : double_booked){
            if(max(start, s) < min(end, e)){
                return false;
            }
        }
        for(const auto& [s,e] : single){
            if(max(start,s) < min(end, e)){
                double_booked.push_back({max(start, s), min(end , e)});
            }
        }
        single.push_back({start, end});
        return true;
    }
};
