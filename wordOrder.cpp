bool isOrdered(vector<string>& wordlist, string order){
        if(wordlist.empty() || wordlist.size()<=1 || order.empty() || order.size()<=1){
            return true;
        }
        unordered_map<char, int> orderMap;
        for(int i=0; i<order.size(); ++i) orderMap[order[i]] = i;
        
        for(int i=1; i<wordlist.size(); ++i){
            if(!checkOrder(wordlist[i-1], wordlist[i], orderMap)) return false;
        }
        return true;
    }
    
    bool checkOrder(string str1, string str2, unordered_map<char, int>& order){
        int len1 = str1.size();
        int len2 = str2.size();
        for(int i=0; i<min(len1, len2); ++i){
            if(str1[i]==str2[i]) continue;
            else{
                //要思考万一字符不在order里面怎么办
                if(order.find(str1[i])!=order.end() && order.find(str2[i])!=order.end() 
                && order[str1[i]]<order[str2[i]]) return true;
                else return false;
            }
        }
        return (len1<=len2);
    }
