class Solution {
public:
    static bool cmp(const Interval&a, const Interval&b){
        return a.start<b.start;
    }
    
    /*
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> rooms;
        sort(intervals.begin(), intervals.end(), cmp);
        for(auto interval: intervals){
            if(rooms.empty() || rooms.top()>interval.start){
                rooms.push(interval.end);
            }
            else{
                rooms.pop();
                rooms.push(interval.end);
            }
        }
        return rooms.size();
    }
    */
    
    struct cmppq{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            return a.first>b.first;
        }
    };
    
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<vector<Interval>> rooms;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmppq> pq;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        for(auto interval: intervals){
            if(pq.empty() || pq.top().first>interval.start){
                pq.push(make_pair(interval.end, rooms.size()));
                rooms.push_back(vector<Interval>(1, interval));
            }
            else{
                int preIndex = pq.top().second;
                pq.pop();
                pq.push(make_pair(interval.end, preIndex));
                rooms[preIndex].push_back(interval);
            }
        }
        for(int i=0; i<rooms.size(); ++i){
            for(int j=0; j<rooms[i].size(); ++j){
                cout<<"["<<rooms[i][j].start<<","<<rooms[i][j].end<<"] ";
            }
            cout<<endl;
        }
        return rooms.size();
    }
};