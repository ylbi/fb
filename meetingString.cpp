//"10a" "10:30a" 

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Interval{
    int start, end;
    Interval(){}
    Interval(int s, int e){
    start = s;
    end = e;
    }
};

vector<string> split(string s, char ch){
	vector<string> result;
	int start = 0;
	for(int i=0; i<s.size(); ++i){
		start = i;
		while(i<s.size() && s[i]!=ch) i++;
		result.push_back(s.substr(start, i-start));
	}
	return result;
}

int convert(string s){
    int time = 0;
    while(s.back()==' ') s.pop_back();

    if(s.back()=='p') time = 12*60;
    s.pop_back();

    vector<string> tmp = split(s, ':');
    if(tmp.size()==1){
        time += (stoi(tmp[0])%12)*60;
    }
    else{
        time += (stoi(tmp[0])%12)*60 + stoi(tmp[1]);
    }
    return time;
}

Interval interpret(string s){
    Interval time;
	vector<string> tmp = split(s, '-');
	int startTime = convert(tmp[0]);
  	int endTime = convert(tmp[1]);
    if(startTime>endTime) endTime += 24*60;
    time.start = startTime;
    time.end = endTime;
	//cout<<time.start<<endl;
    return time;
}

bool cmp(Interval&a, Interval&b){
    return a.start<b.start;   
}

int numberOfRooms(vector<string>& meetings){
    vector<Interval> times(meetings.size());
    priority_queue<int, vector<int>, greater<int>> rooms;

    for(int i=0; i<meetings.size(); ++i){
        auto tmp = interpret(meetings[i]);
        times[i].start = tmp.start;
        times[i].end = tmp.end;
        cout<<times[i].start<<" "<<times[i].end<<endl;
    }

    sort(times.begin(), times.end(), cmp);

    for(int i=0; i<times.size(); ++i){
        //cout<<i<<endl;
    if(rooms.empty() || rooms.top() > times[i].start){
        rooms.push(times[i].end);
    }
    else{
        rooms.pop();
        rooms.push(times[i].end);
    }
    }
    //cout<<rooms.size()<<endl;
    return rooms.size();
}

int main()
{
	vector<string> meetings;
	meetings.push_back("10a-10:30a");
	meetings.push_back("11a-12p");
	meetings.push_back("11:30a-1p");
	meetings.push_back("2p-4p");
	cout<<numberOfRooms(meetings)<<endl;
	return 0;
}