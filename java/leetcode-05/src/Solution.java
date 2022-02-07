public class Solution {
    public static void main(String[] args) {
        String s = "We are happy.";
        Solution solution = new Solution();
        String s1 = solution.replaceSpace(s);
        System.out.println(s1);
    }
    public String replaceSpace(String s) {

        int emptySize = 0;  //空格数量

        //计算空格的数量
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i) == ' '){
                emptySize++;
            }
            else{
                continue;
            }
        }

        char[] c = new char[s.length()+emptySize*2];    //新字符数组
        int j = c.length - 1;

        for(int i = s.length()-1;i>=0;i--){

            if(s.charAt(i) != ' '){
                c[j] = s.charAt(i);
                j--;
            }
            else{
                c[j] = '0';
                c[j-1] = '2';
                c[j-2] = '%';
                j -= 3;
            }
        }
        String result = "";
        for(int i = 0;i<c.length;i++){
            result += c[i];
        }
        return result.toString();
    }
}
