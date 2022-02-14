class Solution {
    public boolean isSymmetric(TreeNode root) {

        if(root == null)
            return true;

        return cmp(root.left,root.right);
    }

    private boolean cmp(TreeNode left,TreeNode right){

        if(left == null && right == null)
            return true;

        if(left != null || right != null || left.val != right.val)
            return false;

        return cmp(left.left,right.right) && cmp(left.right,right.left);
    }
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
}
