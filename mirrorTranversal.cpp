TreeNode* root;
TreeNode* prev;
while (curt != null) {
    if (curt->left == null) {
        cout<<curt->val;
        curt = curt->right;
    }
    else {
        TreeNode* prevNode =  curt->left;
        while (prevNode->right != null && prevNode->right != curt) {
            prevNode = prevNode->right;
        }
        if (prevNode->right == curt) {
            //prevNode->right = null;  //恢复树的结构
            curt = curt->right;
        }
        else {
            prevNode->right = curt;
            curt = curt->left;
        }

    }
}

public Node treeToDoublyList(Node root) {
        if (root == null) return null;
        Node cur = root, first = null, pre = null;
        while (cur != null) {
            if (cur.left == null) {
                if (first == null) first = cur;
                cur.left = pre;
                if (pre != null) pre.right = cur;
                pre = cur;
                cur = cur.right;
            } else {
                Node left = cur.left;
                while (left.right != null && left.right != cur) left = left.right;
                if (left.right == null) {
                    left.right = cur;
                    cur = cur.left;
                } else {
                    cur.left = pre;
                    pre = cur;
                    cur = cur.right;
                }
            }
        }
        pre.right = first;
        first.left = pre;
        return first;
    }