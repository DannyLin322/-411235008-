#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int levelSum = 0;

        while (!q.empty()) {
            int size = q.size(); 
            levelSum = 0;        

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return levelSum;
    }
};