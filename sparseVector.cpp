class SparseVector{
public:
    vector<pair<int, int>> vectors;
    SparseVector(vector<int>& nums){
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=0) 
                vectors.push_back(make_pair(i, nums[i]));
        }
    }
    
    int multiply(SparseVector& v1, SparseVector& v2){
        int i=0, j=0;
        int res = 0;
        while(i<v1.vectors.size() && j<v2.vectors.size()){
            if(v1.vectors[i].first==v2.vectors[j].first) res += v1.vectors[i].second*v2.vectors[j].second;
            else if(v1.vectors[i].first<v2.vectors[j].first) i++;
            else j++;
        }
        return res;
    }
};
