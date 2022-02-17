public class Solution {
    public String between (String chars, String id1, String id2) {
        // write code here
        int id1Code = id1.codePointCount(0, id1.length());
        int id2Code = id2.codePointCount(0,id2.length());

        int left = 0;
        int right = chars.length();

        while(left <= right){

            int midCode = chars.codePointCount(left,right);

            if(midCode > id1Code && midCode < id2Code)
                return chars.substring(left,right);

            else if(midCode <= id1Code)
                left++;

            else if(midCode >= id2Code)
                right--;
        }

        StringBuilder stringBuilder = new StringBuilder();
        int i = 0;

        while(chars.codePointAt(i) < id2Code){
            if(chars.charAt(i) == id1.charAt(0)){
                while(stringBuilder.length() <= id1.length()){
                    stringBuilder.append(chars.charAt(i));
                }
                break;
            }
            else{
                i++;
            }
        }
        return stringBuilder.toString();
    }
}
