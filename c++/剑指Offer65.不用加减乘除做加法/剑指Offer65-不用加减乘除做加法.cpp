class Solution {
public:
    int add(int a, int b) {
        
        if(b == 0) return a;

        return add(a ^ b, static_cast<unsigned int>(a & b) << 1);
    }
};