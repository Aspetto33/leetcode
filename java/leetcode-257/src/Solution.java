import java.util.ArrayList;
import java.util.List;

public class Solution {
    class TreeNode {
       int val;
       TreeNode left;
       TreeNode right;
       TreeNode() {}
       TreeNode(int val) { this.val = val; }
       TreeNode(int val, TreeNode left, TreeNode right) {
           this.val = val;
           this.left = left;
           this.right = right;
       }
   }

    public List<String> binaryTreePaths(TreeNode root) {

        List<String> result = new ArrayList<>();

        spl(root,"",result);

        return result;
    }

    private void spl(TreeNode root,String str,List<String> list){

        if(root == null)
            return;

        str += root.val;
        if(root.left == null && root.right == null){
            list.add(str);
        }
        else{
            spl(root.left,str+"->",list);
            spl(root.right,str+"->",list);
        }
    }
}
