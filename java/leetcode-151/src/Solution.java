public class Solution {
    public static void main(String[] args) {
        String s = "the sky is blue";
        Solution solution = new Solution();
        String s1 = solution.reverseWords(s);
        System.out.println(s1);
    }
        public String reverseWords(String s) {

            StringBuilder sb = trimSpaces(s);

            reverse(sb,0,sb.length()-1);

            reverseEachWords(sb);

            return sb.toString();
        }

        //反转整个字符串
        private void reverse(StringBuilder s,int start,int end){

            while(start <= end){
                char tmp = s.charAt(start);
                s.setCharAt(start,s.charAt(end));
                s.setCharAt(end,tmp);
                start++;
                end--;
            }
        }

        //反转单个字符串
        private void reverseEachWords(StringBuilder s){

            int start = 0;  //单个字符串的起始位置
            int end = 0;    //单个字符串的终点位置

            while(start < s.length()){
                while(end < s.length() && s.charAt(end) != ' ')
                    end++;

                reverse(s,start,end - 1);

                start = end + 1;
                end++;
            }
        }

        //去除多余空格
        private StringBuilder trimSpaces(String s){

            int start = 0;
            int end = s.length() - 1;

            while(start <= end && s.charAt(start) == ' '){
                start++;
            }

            while(start <= end && s.charAt(end) == ' '){
                end--;
            }

            StringBuilder sb = new StringBuilder();
            while(start <= end){
                char c = s.charAt(start);

                if(c != ' '){
                    sb.append(c);
                }
                else if(sb.charAt(sb.length()-1) != ' '){
                    sb.append(c);
                }
                start++;
            }
            return sb;
        }
}
