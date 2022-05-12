class Solution {
public:
    TreeNode* helper(vector<int>& inorder, int si, int ei, vector<int>& postorder, int sp, int ep){
        // base case 
        if (si > ei || sp > ep){
            return NULL;
        }
        
        // root is the last element of postorder 
        TreeNode* root = new TreeNode(postorder[ep]);
        
        int x = si;
        
        // finding root in inorder 
        while (inorder[x] != postorder[ep]){
            x++;
        }
        
        // divide the array in left subtree and right subtree 
        // and call the same function for the left and right subtrees of inorder and postorder 
        root->left = helper(inorder, si, x - 1, postorder, sp, sp + x - si - 1);
        root->right = helper(inorder, x + 1, ei, postorder, sp + x - si, ep - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
