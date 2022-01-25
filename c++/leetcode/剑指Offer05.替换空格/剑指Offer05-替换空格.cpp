class Solution {
public:
    string replaceSpace(string s) {
       int count = 0;
       int oldsize = s.size();
       for(int i=0;i<oldsize;i++){
           if(s[i]==' '){
               count++;
           }
       }
       int newsize = oldsize+count*2;
       s.resize(newsize);
       for(int i=newsize-1,j=oldsize-1;j<i;i--,j--){
           if(s[j]!=' '){
               s[i]=s[j];
           }else{
               s[i]='0';
               s[i-1]='2';
               s[i-2]='%';
               i-=2;
           }
       }
       return s;
    }
};