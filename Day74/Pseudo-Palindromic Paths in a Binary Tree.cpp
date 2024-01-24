class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> array(10,0);
        path(array,count,root);
        return count;
    }
    void path(vector<int> &array,int &count,TreeNode* &root)
    {
        if(!root) return;
        array[root->val]++;
        path(array,count,root->left);
        path(array,count,root->right);
        
        if(!root->left && !root->right)
        {
            int flag = 0;
            for(int i = 1; i <=9; i++)
            {
                if(array[i]%2!=0) flag++;
            }
            if(flag == 1 || flag == 0) count++;
        }
        array[root->val]--;
    }
};
