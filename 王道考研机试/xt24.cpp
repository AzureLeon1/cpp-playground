// Repeater
// 模拟-图形排版：在内存中完成排版，然后再输出
// 排版过程采用DFS，即通过递归的方式寻找所有绘图的起点，以原图为单位进行绘图（也可以用循环的方式去做）
// 大数组开在main()外，防止栈溢出
// 字符相关：注意char[]多开一个大小；getchar()吸收换行符；cin.getline()第二个参数是n+1

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n;                    // base map的行数
int p;                    // 倍数
char base[6][6];          // base map
char map[3001][3001];     // result map

// 通过dfs寻找左上角的起点
// (x, y)是左上角的起点
// 以原图为单位进行绘图：level > 1时，继续寻找绘图起点；level = 1时，从左上角起点开始绘图
void dfs(int x, int y, int level) {
    if (level == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[x+i][y+j] = base[i][j];
            }
        }
        return;
    }

    int size = pow(n, level-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (base[i][j] != ' ') {
                dfs(x + i * size, y + j * size, level - 1);
            }
        }
    }

}


int main (){

    // int x = (int)pow(3*1.0, 3 - 1);
    // int y = pow(3, 2);
    // cout << x << ' ' << y << endl;
    

    while(cin >> n)  {
        if (n == 0) break;

        getchar();  // 吸收换行符
        
        for (int i = 0; i < n; i++){
            cin.getline(base[i], n+1);    // 注意是n+1，最后一个字符是'\0'
            // cout << base[i] << endl;
        }

        cin >> p;

        memset(map, ' ', sizeof(map));


        dfs(0, 0, p);

        int size = pow(n, p);
        for (int i = 0; i < size; i++) {
            map[i][size] = '\0';
            cout << map[i] << endl;
        }

    }

    return 0;
}

