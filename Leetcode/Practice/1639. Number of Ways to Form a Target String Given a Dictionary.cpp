#define mod 1000000007

class Solution {
public:
    int n, m, tlen;
    string tStr;
    vector<vector<int> >cnts;
    vector<vector<long long int> >dp;

    int solve(int t, int d) {
        if (t >= tlen)
            return 1;
        if (d >= m)
            return 0;
        if (tlen - t > m - d)
            return dp[t][d] = 0;

        if (dp[t][d] != -1)
            return dp[t][d];

        int oc = cnts[ tStr[t] - 'a' ][d];

        if (oc == 0)
            return dp[t][d] = solve(t, d + 1) % mod;

        return dp[t][d] = ((oc * ((long long int)solve(t + 1, d + 1) % mod)) % mod + solve(t, d + 1) % mod) % mod;
    }

    int numWays(vector<string>& words, string target) {

        n = words.size();
        m = words[0].length();
        tlen = target.length();
        tStr = target;

        cnts.assign(27, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnts[ words[j][i] - 'a' ][i]++;
            }
        }
        dp.assign(tlen + 1, vector<long long int>(m + 1, -1));

        return solve(0, 0) % mod;
        // return 1;
    }
};