
class Solution {
public:
    vector<int> buildLPS(string &b) {
        int m = b.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (b[i] == b[len]) {
                lps[i] = ++len;
                i++;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }

        return lps;
    }

    bool kmpSearch(string &text, string &b, vector<int> &lps) {
        int i = 0, j = 0;
        int n = text.size(), m = b.size();

        while (i < n) {
            if (text[i] == b[j]) {
                i++;
                j++;

                if (j == m) return true;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int k = (b.size() + a.size() - 1) / a.size();

        string text = "";
        for (int i = 0; i < k; i++) {
            text += a;
        }

        vector<int> lps = buildLPS(b);

        if (kmpSearch(text, b, lps)) return k;

        text += a;
        if (kmpSearch(text, b, lps)) return k + 1;

        return -1;
    }
};
