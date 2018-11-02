class NestedInteger{
    NestedInteger();
    bool isInteger();
    int getInteger();
    vector<NestedInteger> &getList();
}

string helper(vector<NestedInteger>& nestedList, int level){
    string res = "";
    string tmp = "";
    for(NestedInteger item: nestedList){
        if(item.isInteger()){
            res += to_string(item.getInteger()) + "+";
        }
        else{
            tmp = helper(item.getList(), level+1);
            if(tmp=="") continue;
            res += tmp+"+";
        }
    }
    if(!res.empty()) res.pop_back();
    
    if(level==1) return res;
    else return "("+res+")"+"*"+to_string(level);
}

int depthSum(vector<NestedInteger>& nestedList) {
    string res = helper(nestedList, 1);
    cout<<res<<endl;
    return 0;
}