class Solution {
public:
int value(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000; 
    }
    int romanToInt(string s) {
       int ans = 0 ;
       for(int i = 0 ; i < s.length() ; i++){
        int curr = value(s[i]);
        int next = 0 ;

        if(i + 1 < s.length()){
            next = value(s[i+1]);
        }
        if(curr < next){
            ans-= curr;
        }
        else{
            ans+= curr;
        }
       } 
       return ans;
    }
};