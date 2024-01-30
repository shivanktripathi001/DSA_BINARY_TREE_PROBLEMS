
class Solution {
public:
    map<int,int> mp;
    void mapping (vector<int>& inorder,int size){

        for(int i=0;i<size;i++){
            mp[inorder[i]]=i;
        }
    }

     TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int size,int inorderstart,int inorderend,int &postidx){


         if(postidx < 0 ||inorderstart>inorderend ){

             return NULL;
         }

         int ele = postorder[postidx];
         postidx--;

         int pos = mp[ele];

         TreeNode* root = new TreeNode(ele);


         
         root->right =  solve(inorder,postorder,size,pos+1,inorderend,postidx);   
         root->left =  solve(inorder,postorder,size,inorderstart,pos-1,postidx);
   


        return root;


     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size =inorder.size();
        int inorderstart = 0;
        int inorderend = size-1;
        int postidx = size-1;

     mapping(inorder,size);

      TreeNode* binarytree =   solve(inorder,postorder,size,inorderstart,inorderend,postidx);   

      return binarytree;
    }
};
