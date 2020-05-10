/*本题最重要的逻辑是蚂蚁的相对位置永远不变！！这个逻辑直接推导出了本题的解法之一
 有参考 http://www.cnblogs.com/liangrx06/p/5083868.html
  不过因为没有注解，所以自己写了一点
首先，我们来确定怎么判断蚂蚁不会坠落，有两种情况————
   第一种：静止的蚂蚁两边的蚂蚁都不会碰到这只蚂蚁，也就是说，左边的往左走，右边的往右走
   第二种：蚂蚁的右边有向左走的，左边有向右走的，按照一般的理解一开始静止的蚂蚁一定
   是会掉下去的，但是注意一开始提到的那个逻辑，蚂蚁的相对位置不变，并且移动方向也不变！
   什么意思呢，比如整个树枝上向左走有n个，向右走有m个。那么在任何时间向左走和向右走的
   数量都是n和m，这时候结合蚂蚁的相对位置，在无限的时刻，向左走的n只蚂蚁都掉下了树枝，
   这n只不一定都是原来初始状态向左走的，但一定是一开始左边的n只蚂蚁，因为相对位置不变。
   同理，右边m只也都掉出去了，那么如果n==m，并且静止的蚂蚁左右都有n(m)只。那么，在某个时刻，
   左边n只无论之前是向哪里走的，一定都下去了。
   所以，我们把结论推广，只要静止的蚂蚁左边的蚂蚁数量，等于所有蚂蚁中往左走的数量，
   亦或者右边的等于向右走的那么它就不会掉下去。
     
那么，怎么判断蚂蚁什么时候下去呢
   这时候肯定能确定这只蚂蚁左右数量不等了。接下来就是很巧妙的思想了，如果该蚂蚁
   左边的蚂蚁数量小于向左走的蚂蚁数量,那么它总会加入向左走的大军最后掉落。这时候
   我们宏观的去看，我们定位所有在向左走的蚂蚁，并且定位静止的那只蚂蚁的位置，并且
   标记为k(第k个蚂蚁)，这时开始移动，我们看不到蚂蚁之间交换速度，我们只知道他们
   像是穿过对方继续往下走。让蚂蚁继续走，直到某一刻我们观察到第k只向左走的蚂蚁
   掉下去了，暂停。现在考虑所有蚂蚁的相对位置不变！如果是第k个向左走的蚂蚁下去了
   那么他之前的向左走的蚂蚁都下去了，反映到相对位置上来说，就是树枝上左边k-1只都下去了，
   那么这一瞬间掉下去的想必就是相对位置在第k的蚂蚁了————也就是原来静止的那只。
   也就是说一开始所有向左走的蚂蚁中，第k个蚂蚁要走多远，就是最终答案！！
   同样，如果反过来，右边的少于向右走的，也一样，
*/
 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
 
struct Ant
{
    int position;
    int direct;    //方向
    bool operator < (const Ant &a) const
    {
        return position<a.position;
    }
};
 
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        vector<Ant> ant(n);
        for(int i = 0; i<n; i++)
            scanf("%d %d",&ant[i].position,&ant[i].direct);
        sort(ant.begin(),ant.end());
        //////接下来要做的就是找到静止的那只的位置，为此我们要先排序
        //这样找到的静止的蚂蚁左边有几只就出来了
        int target,toLeft = 0;    //这里选用向左走的为基准来做
        for(int i = 0; i<n; i++)    //遍历所有蚂蚁
        {
            if(ant[i].direct == 0)
                target = i;
            if(ant[i].direct == -1)
                toLeft++;
        }//现在的target就是静止的蚂蚁左边的数量了
        bool flag = false;
        int ans;
        if(toLeft == target)
            flag = true;
        else if (toLeft > target)//这样的话我们要找的就是所有向左走的蚂蚁中，第target蚂蚁
        {
            int cnt = 0;//计数器
            for(int i = 0; i<n; i++)
            {
                if(ant[i].direct == -1 && cnt == target)
                {
                    ans = ant[i].position;
                    break;
                }
                else if(ant[i].direct == -1)
                    cnt++;
            }
        }
        else    //向左走的蚂蚁少，那么目标蚂蚁会向右落下
        {
            int cnt = 0;
            for(int i = n - 1; i>=0; i--)
            {
                if(ant[i].direct == 1 && cnt == n - target - 1)//相应的变化，cnt要变成静止蚂蚁右边的蚂蚁数量
                {
                    ans = 100 - ant[i].position;
                    break;
                }
                else if(ant[i].direct == 1)
                    cnt++;
            }
        }
        if(flag)
            printf("Cannot fall!\n");
        else
            printf("%d\n",ans);
    }//while
    return 0;
}//main