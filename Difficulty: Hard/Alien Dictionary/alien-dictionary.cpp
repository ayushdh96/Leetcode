class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<int, vector<int>> mpp;   // edges u -> v
        vector<int> present(26, 0);            // track letters that appear

        // mark all present letters
        for (auto &w : words) for (char c : w) present[c - 'a'] = 1;

        // build edges from adjacent pairs (+ handle invalid prefix)
        for (int i = 0; i + 1 < (int)words.size(); i++) {
            string &idx1 = words[i];
            string &idx2 = words[i + 1];
            int L = min((int)idx1.size(), (int)idx2.size());

            int j = 0;
            while (j < L && idx1[j] == idx2[j]) j++;

            if (j < L) {
                mpp[idx1[j] - 'a'].push_back(idx2[j] - 'a');
            } else {
                if ((int)idx1.size() > (int)idx2.size()) return ""; // invalid
            }
        }

        // indegree for all 26 (we'll only process 'present' ones)
        vector<int> indegree(26, 0);
        for (auto &it : mpp) {
            for (int v : it.second) indegree[v]++;
        }

        // Kahn's BFS
        queue<int> q;
        for (int u = 0; u < 26; u++) {
            if (present[u] && indegree[u] == 0) q.push(u);
        }

        string ans;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(char(u + 'a'));
            for (int v : mpp[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        // validate: produced all present letters?
        int presentCount = 0;
        for (int x : present) presentCount += x;
        if ((int)ans.size() != presentCount) return "";

        return ans;
    }
};