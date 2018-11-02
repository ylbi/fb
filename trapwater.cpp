//-1
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        vector<int> leftMaxIndex(height.size(), 0);
        vector<int> rightMaxIndex(height.size(), 0);
        int total = 0;
        
        leftMaxIndex[0] = 0;
        for(int i=1; i<height.size(); ++i){
            leftMaxIndex[i] = (height[leftMaxIndex[i-1]]>height[i])?leftMaxIndex[i-1]:i;
            leftMaxIndex[i] = (height[i] == -1)?i:leftMaxIndex[i];
        }
        
        rightMaxIndex[height.size()-1] = height.size()-1;
        for(int i=height.size()-2; i>=0; --i){
            rightMaxIndex[i] = (height[rightMaxIndex[i+1]]>height[i])?rightMaxIndex[i+1]:i;
            rightMaxIndex[i] = (height[i] == -1)?i:rightMaxIndex[i];
        }
        
        for(int i=1; i<height.size()-1; ++i){
            if(height[leftMaxIndex[i-1]]!=-1 && height[rightMaxIndex[i+1]]!=-1 && height[i]!=-1)
                total += max(0, min(height[leftMaxIndex[i-1]], height[rightMaxIndex[i+1]]) - height[i]);
        }
        return total;
    }
