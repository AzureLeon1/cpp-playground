// 法一：在内存中生成矩阵然后输出
// 法二：找规律，每行要输出的元素跟当前的行数之间存在关系

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;

        int len = s.length();

        int unit_capicity = numRows + (numRows - 2);
        int unit_cols = numRows - 1;
        int unit_cnt = len / unit_capicity;
        if (len % unit_capicity > 0) unit_cnt++;

        int total_cols = unit_cols * unit_cnt;

        char map[numRows+1][total_cols+1];
        memset(map, 0, sizeof(map));

        int index = 0;
        for (int n = 0; n < unit_cnt; n++) {
            int x = 0;
            int y = unit_cols * n;
            for (int i = 0; i < numRows; i++) {
                map[x][y] = s[index];
                x++;
                index++;
                if (index >= len) break;
            }
            x--;
            for (int i = 0; i < numRows - 2; i++) {
                if (index >= len) break;
                x--; y++;
                map[x][y] = s[index];
                index++;
            }
        }
        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < total_cols; j++) {
                if (map[i][j]!=0) {
                    res += map[i][j];
                }
            }
        }
        return res;

    }
};