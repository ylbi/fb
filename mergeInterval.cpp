vector<Interval> mergeIntervals(vector<Interval>& in1, vector<Interval>& in2){
  int len1 = in1.size();
  int len2 = in2.size();
  vector<Interval> in3;
  int i=0, j=0;
  Interval smaller;
  
  while(i<len1 || j<len2){
    if(i>=len1){
      smaller = in2[j++];
    }
    else if(j>=len2){
      smaller = in1[i++];
    }
    else if(in1[i].start <= in2[j].start){
      smaller = in1[i++];
    }
    else{
      smaller = in2[j++];
    }
    if(in3.empty() || in3.back().end < smaller.start){
      in3.push_back(smaller);
    }
    else{
      in3.back().end = max(in3.back().end, smaller.end);
    }
  }
  
  return in3;
}