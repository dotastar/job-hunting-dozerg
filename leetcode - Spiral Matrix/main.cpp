#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> r;
        if(matrix.empty() || matrix[0].empty())
            return r;
        int i = 0, j = 0, k = 0;
        const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int t = -1, b = matrix.size(), le = -1, ri = matrix[0].size();
        for(;;){
            r.push_back(matrix[i][j]);
            bool e = true;
            for(int m = 0;m < 2;++m){
                int ni = i + d[k][0];
                int nj = j + d[k][1];
                if(ni <= t || ni >= b || nj <= le || nj >= ri){
                    k = (k + 1) % 4;
                    switch(k){
                        case 0:le = j;break;
                        case 1:t = i;break;
                        case 2:ri = j;break;
                        default:b = i;break;
                    }
                }else{
                    i = ni;
                    j = nj;
                    e = false;
                    break;
                }
            }
            if(e)
                break;
        }
        return r;
    }
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > r;
        if(n <= 0)
            return r;
        r.resize(n, vector<int>(n, 0));
        int i = 0, j = 0, k = 0;
        const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int t = -1, b = n, le = -1, ri = n;
        for(int v = 1;;){
            r[i][j] = v++;
            bool e = true;
            for(int m = 0;m < 2;++m){
                int ni = i + d[k][0];
                int nj = j + d[k][1];
                if(ni <= t || ni >= b || nj <= le || nj >= ri){
                    k = (k + 1) % 4;
                    switch(k){
                        case 0:le = j;break;
                        case 1:t = i;break;
                        case 2:ri = j;break;
                        default:b = i;break;
                    }
                }else{
                    i = ni;
                    j = nj;
                    e = false;
                    break;
                }
            }
            if(e)
                break;
        }
        return r;
    }
};

class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        const pair<int, int> kDir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> v(matrix.size(), vector<bool>(matrix[0].size()));
        vector<int> ret;
        pair<int, int> c(0, -1);
        for(int i = 0, f = 0;f < 2;){
            pair<int, int> n(c.first + kDir[i].first, c.second + kDir[i].second);
            if(0 <= n.first && n.first < matrix.size() && 0 <= n.second && n.second < matrix[0].size() && !v[n.first][n.second]){
                f = 0;
                c = n;
                ret.push_back(matrix[c.first][c.second]);
                v[c.first][c.second] = true;
            }else{
                ++f;
                i = ++i % 4;
            }
        }
        return ret;
    }
};

int main(){}