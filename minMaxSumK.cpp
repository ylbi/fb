//For a given vector of integers and integer K, find the number of non-empty subsets S such that min(S) + max(S) <= K
//For example, for K = 10 and vector [2, 4, 5, 7], the solution is 5 and these are all the subsets that satisfy the requirements: [2], [4], [2, 4], [2,5],[5]


int subsets(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    int i=0, j=0;
    int maxSum = 0;
    int cnt = 0;
    while(i<nums.size() && j<nums.size()){
        if(2*nums[i]<=target){
            while(j<nums.size() && maxSum+nums[j]<=target){
                maxSum += nums[j++];
            }
            cnt += pow(2, j-i-1);
            maxSum -= nums[i++];
        }
        else break;
    }
    return cnt;
}
