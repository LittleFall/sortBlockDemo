///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//#define LL long long
//class Solution {
//public:
//
//    vector<LL> sum;
//    vector<LL> fxxk;
//    vector<LL> sumcnt;
//    vector<LL> fxxkcnt;
//    LL ans=-0x3f3f3f3f3f3f3f3f;
//    int mxdep=0;
//    void getsum(TreeNode* cur,int depth)
//    {
//        if (sum.size()<=depth)
//        {
//            sum.push_back(0);
//            sumcnt.push_back(0);
//        }
//        sum[depth]+=cur->val;
//        sumcnt[depth]++;
//        if (cur->left)
//            getsum(cur->left,depth+1);
//        if (cur->right)
//            getsum(cur->right,depth+1);
//    }
//
//
//    void getsum1(TreeNode* cur,int depth)
//    {
//        mxdep=max(mxdep,depth);
//        fxxk[depth]+=cur->val;
//        fxxkcnt[depth]++;
//        if (cur->left)
//            getsum1(cur->left,depth+1);
//        if (cur->right)
//            getsum1(cur->right,depth+1);
//    }
//
//
//    void getfxxk(TreeNode* cur,int depth,int flag)
//    {
//        if (flag && (cur->left!=NULL)+ (cur->right!=NULL)<=1)
//        {
//            mxdep=0;
//            getsum1(cur,depth);
//            //cout<<cur->val<<' '<<depth<<' '<<mxdep<<endl;
//            for (int i=depth;i<mxdep;i++)
//            {
//                ans=max(ans,sum[i]-fxxk[i]+fxxk[i+1]);
//            }
//            if (fxxkcnt[mxdep]<sumcnt[mxdep])
//                ans=max(ans,sum[mxdep]-fxxk[mxdep]);
//            for (int i=depth;i<=mxdep;i++)
//                fxxk[i]=fxxkcnt[i]=0;
//        }
//        if (cur->left!=NULL && cur->right!=NULL)
//            flag=1;
//        else
//            flag=0;
//        if (cur->left)
//            getfxxk(cur->left,depth+1,flag);
//        if (cur->right)
//            getfxxk(cur->right,depth+1,flag);
//    }
//
//
//
//    int getMaxLayerSum(TreeNode* root) {
//        getsum(root,0);
//        fxxk.resize(sum.size()+1);
//        fxxkcnt.resize(sum.size()+1);
//        for (auto p:sum)
//            ans=max(ans,p);
//        getfxxk(root,0,1);
//        //cout<<ans<<endl;
//        return ans;
//    }
//};