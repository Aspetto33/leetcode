class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {

        return recur(postorder,0,postorder.size()-1);
    }

    bool recur(vector<int>& postorder,int i,int j){

        if(i>=j) return true;

        int p = i;
        while(postorder[p]<postorder[j]) p++;

        int m = p;
        while(postorder[m]>postorder[j]) m++;

        return m == j && recur(postorder,i,p-1) && recur(postorder,p,j-1);
    }
};