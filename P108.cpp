#include "header.h"
#include <vector>

class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return work(nums,0,nums.size());
        }
        TreeNode* work(vector<int> &nums, int ll, int rr) {
            if (rr-ll<=0) return nullptr;
            cout << ll << " "<<rr << endl;
            int mid = ll+ ((rr-ll)>>1);
            TreeNode* root = new TreeNode(nums[mid]);
            if (rr-ll==1) return root;
            if (mid>ll) {
                    root->left = work(nums,ll,mid);
            }
            if (mid+1<rr){
                    root->right = work(nums,mid+1,rr);
            }
            return root;

        }
};

int main(int argc, const char *argv[]) {
    vector<int> a= {-10,-3,0,5,9};
    vector<int> b = {1,2,3,4,5,6,7,8,9,10};
    TreeNode * root = Solution().sortedArrayToBST(b);
    root->print_order();
    return 0;
}

