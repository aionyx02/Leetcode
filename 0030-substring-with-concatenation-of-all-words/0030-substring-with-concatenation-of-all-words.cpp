class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].size();
        int num_words = words.size();
        int total_len = word_len * num_words;
        if (s.size() < total_len) return result;

        unordered_map<string, int> target_map;
        for (const string& w : words) {
            target_map[w]++;
        }

        for (int i = 0; i < word_len; ++i) {
            unordered_map<string, int> seen;
            int left = i;

            for (int right = i; right + word_len <= s.size(); right += word_len) {
                string word = s.substr(right, word_len);

                if (target_map.count(word)) {
                    seen[word]++;

                    while (seen[word] > target_map[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        left += word_len;
                    }

                    if (right - left + word_len == total_len) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};