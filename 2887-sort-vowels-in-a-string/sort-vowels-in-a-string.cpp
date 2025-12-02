class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};

        vector<char> vowelChars;

        // Step 1: Extract vowels from the string
        for (char ch : s) {
            if (vowels.count(ch)) {
                vowelChars.push_back(ch);
            }
        }

        // Step 2: Sort the vowels by ASCII order
        sort(vowelChars.begin(), vowelChars.end());

        // Step 3: Reconstruct the string
        int vowelIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.count(s[i])) {
                s[i] = vowelChars[vowelIndex++];
            }
        }

        return s;
    }
};