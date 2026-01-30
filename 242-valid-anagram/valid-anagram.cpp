class Solution {
public:
       bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map <int , int> sp;
        unordered_map <int , int> tp;
        for(int i = 0 ; i < s.size();i++){
            sp[s[i]]++;
        }
        for(int j = 0 ; j < t.size(); j++){
            tp[t[j]]++;
        }
        for(int i = 0 ; i < s.size();i++){
            if(sp[s[i]] != tp[s[i]]){
                return false;
            }
        }
        return true;
    }
};
