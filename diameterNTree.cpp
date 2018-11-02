struct TreeNode{
    int val;
    vector<TreeNode*> children;
    TreeNode(int x){
        val = x;
    }
};

class Diameter{
    int maxLen;
    int maxDiameter(TreeNode *root){
        maxLen = 0;
        helper(root);
        return maxLen;
    }
    int helper(TreeNode *root){
        if(root==NULL) return 0;
        int firstHeight = 0, secondHeight = 0;
        int curHeight = 0;
        for(TreeNode *child: root->children){
            curHeight = helper(child);
            if(curHeight>firstHeight){
                secondHeight = firstHeight;
                firstHeight = curHeight;
            }
            else if(curHeight>secondHeight){
                secondHeight = curHeight;
            }
        }
        maxLen = max(maxLen, firstHeight+secondHeight);
        return firstHeight+1;
    }
}