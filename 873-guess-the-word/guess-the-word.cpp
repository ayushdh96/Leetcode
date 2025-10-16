/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int n;
    set<string> cands;

    int countMatches(const string& a, const string& b){
        int count = 0;
        for (int i = 0; i < 6; i++){
            if (a[i] == b[i]) count++;
        }
        return count;
    }

    void wordGuesser(int lastM, string& lastWord, Master& master, vector<string>& words){
        if (cands.size() == 0) return;
        for (auto it = cands.begin(); it != cands.end(); ) {
            if (countMatches(lastWord, *it) != lastM) it = cands.erase(it);
            else it++;
        }

        int guess = rand() % cands.size();
        string word = *next(cands.begin(), guess);
        cands.erase(word);

        int m = master.guess(word);
        if (m == 6) return;
        wordGuesser(m, word, master, words);
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        n = words.size();
        cands.insert(words.begin(), words.end());
        
        int firstG = rand() % n;
        int m = master.guess(words[firstG]);
        if (m == 6) return;

        cands.erase(words[firstG]);
        wordGuesser(m, words[firstG], master, words);
    }
};