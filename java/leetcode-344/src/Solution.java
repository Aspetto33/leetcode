public class Solution {
    public static void main(String[] args) {
        char[] s = {'h','e','l','l','o'};
        Solution solution = new Solution();
        solution.reverseString(s);

        for(int i = 0;i<s.length;i++){
            System.out.println(s[i]);
        }
    }
    private static void swap(char[] s,int a,int b){
        char tmp = s[a];
        s[a] = s[b];
        s[b] = tmp;
    }
    public void reverseString(char[] s) {

        int left = 0;   //左指针
        int right = s.length - 1;   //右指针

        while(left < right){
            Solution.swap(s,left,right);
            left++;
            right--;
        }
    }


}
