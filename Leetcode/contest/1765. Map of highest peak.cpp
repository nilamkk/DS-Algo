class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();

        queue<pair<int, int> >q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }
        int dis = 1, ans = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto x = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    if (x.first + dx[j] >= 0 &&
                            x.first + dx[j] < n &&
                            x.second + dy[j] >= 0 &&
                            x.second + dy[j] < m &&
                            isWater[x.first + dx[j]][x.second + dy[j]] == -1)
                    {
                        isWater[x.first + dx[j]][x.second + dy[j]] = dis;
                        q.push({x.first + dx[j], x.second + dy[j]});
                        ans = max(ans, dis);
                    }
                }
            }
            dis++;
        }
        return isWater;
    }
};