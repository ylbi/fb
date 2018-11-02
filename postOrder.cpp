class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> postorder;
        TreeNode *pre = root, *cur = root;
        
        if(root!=NULL) stk.push(root);
        while(!stk.empty()){
            cur = stk.top();
            if((cur->left==NULL && cur->right==NULL) ||
              (cur->right==NULL && cur->left==pre)||
              (cur->right==pre)){
                postorder.push_back(cur->val);
                pre = cur;
                stk.pop();
            }
            else{
                //Push right first, because we have to traverse left first. 
                if(cur->right) stk.push(cur->right);
                if(cur->left) stk.push(cur->left);
            }
        }
        return postorder;
    }
};