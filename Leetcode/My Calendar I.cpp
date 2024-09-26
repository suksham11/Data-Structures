class MyCalendar {
public:
    vector<pair<int, int>>events;
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(const auto& event : events){
            int rs = event.first;
            int re = event.second;
            if(start < re && end > rs){
                return false;
            }
        }
        events.push_back(make_pair(start, end));
        return true;
    }

  
};
