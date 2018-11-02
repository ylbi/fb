class BSTIterator {
private:
    stack<TreeNode*> stk;
    TreeNode* cur;
    TreeNode* pre;
public:
    BSTIterator(TreeNode *root) {
        if(root) stk.push(root);
        cur = root;
        pre = root;
        hasNext();
    }
    
    bool hasNext() {
        while(!stk.empty()){
            cur = stk.top();
            if(cur->left==NULL && cur->right==NULL ||
                cur->right==NULL && pre == cur->left ||
                pre == cur->right){
                break;
            }
            else{
                if(cur->right) stk.push(cur->right);
                if(cur->left) stk.push(cur->left);
            }
        }
        return !stk.empty();
    }

    int next() {
        hasNext();
        int tmp = stk.top()->val;
        pre = stk.top();
        stk.pop();
        return tmp;
    }
};