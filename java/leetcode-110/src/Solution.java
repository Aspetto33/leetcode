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
    public boolean isBalanced(TreeNode root) {

        if(root == null)
            return true;

        if(Math.abs(nodeCount(root.left) - nodeCount(root.right))>1)
            return false;

        return isBalanced(root.left) && isBalanced(root.right);

    }
    private int nodeCount(TreeNode root){

        if(root == null)
            return 0;

        else
            return Math.max(nodeCount(root.left),nodeCount(root.right)) + 1;
    }
}
