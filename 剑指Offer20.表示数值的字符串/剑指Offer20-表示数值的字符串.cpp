class Solution {
public:
    bool isNumber(string s) {

         if (s=="") return false;
        string str="";
        int fg1=0,fg2=0;
        for(int i=0;i<s.size();i++){  //È¥µô¿Õ¸ñ
            if (s[i]==' '){
                if (fg1==1) fg2=1;
            }
            else{
                if (fg2==1) return false;
                fg1=1;
                str=str+s[i];
            }
        }
        //cout<<s<<isint(str)<<isfloat(str)<<ise(str)<<endl;
        return isint(str) || isfloat(str) || ise(str);

    }
    bool isint(string s){
        if (s=="") return false;
        int fg1=0,fg2=0;
        for (int i=0;i<s.size();i++){
            if (s[i]>='0' && s[i]<='9'){
                fg1=1;
            }
            else if(s[i]==' '){
                if (fg1==1){
                    return false;
                }
            }
            else if (s[i]=='+' || s[i]=='-'){
                if (fg1==1 || fg2==1) return false;
                if (i+1<s.size() && s[i+1]>='0' && s[i+1]<='9'){
                }
                else {return false;}                
                fg1=1;
                fg2=1;
            }
            else{
                return false;
            }
        }
        if (fg1==0) return false;
        return true;
    }
    bool isfloat(string s){
        int fg1=0,fg2=0;
        string s1="",s2="";
        for (int i=0;i<s.size();i++){
            if (s[i]=='.'){
                if (fg1==1) return false;
                if (i+1<s.size()){
                    if (s[i+1]>='0' && s[i+1]<='9'){
                    }
                    else{
                        return false;
                    }
                }
                fg1=1;
            }
            else{
                if (fg1==0){
                    s1=s1+s[i];
                }
                else{
                    s2=s2+s[i];
                }
            }           
        }
        //if (s1=="" && s2=="") return false;
        if ((s1=="" || s1=="+" || s1=="-"|| isint(s1)) && (isint(s2))) return true;
        if (isint(s1) && (s2=="" || isint(s2))) return true;
        return false;
    }
    bool ise(string s){
        int fg1=0,fg2=0;
        string s1="",s2="";
        for (int i=0;i<s.size();i++){
            if (s[i]=='e' || s[i]=='E'){
                if (fg1==1) return false;
                if (i+1<s.size()){
                }
                else {return false;}
                fg1=1;
            }
            else{
                if (fg1==0){
                    s1=s1+s[i];
                }
                else{
                    s2=s2+s[i];
                }
            }           
        }
        return (isint(s1) || isfloat(s1)) && (isint(s2)) ;
    }
};