#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<int> SieveofEratosthenes()
{
    unordered_set<int> s;
    vector<bool> prime(10000, true);
    for (int i = 2; i * i < 10000; i++)
    {
        if (prime[i])
        {
            for (int p = i * i; p <= 10000; p += i)
                prime[p] = false;
        }
    }
    for (int i = 1000; i < 10000; i++)
    {
        if (prime[i])
            s.insert(i);
    }
    return s;
}

int change(int n, int j, int k)
{
    vector<int> num;
    j = 4 - j;
    while (n > 0)
    {
        int a = n % 10;
        num.push_back(a);
        n = n / 10;
    }
    num[j] = k;
    int a = 1000;
    int s = 0;
    for (int i = 3; i >= 0; i--)
    {
        s = s + num[i] * a;
        a = a / 10;
    }
    return s;
}

int primeSteps(int n1, int n2)
{
    // FILE *f=fopen("result.txt","w");
    unordered_set<int> s = SieveofEratosthenes();
    vector<bool> mark(10000, false);
    queue<pair<int, int>> q;
    q.push(make_pair(0, n1));
    int u = 0;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        u = temp.first;
        int n = temp.second;
        // cout << u <<" " << n<<endl;
        // fprintf(f,"%d %d\n",u,n);
        mark[n] = true;
        if (n == n2)
            return u;
        u++;
        for (int i = 0; i <= 9; i++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if ((i == 0 && k == 1) || (i % 2 == 0 && k == 4))
                    continue;
                else
                {
                    int j = change(n, k, i);
                    // if(n==3733)
                    // cout << j << endl;
                    if (s.find(j) != s.end() && mark[j] == false)
                    {
                        // cout << j<< " ";
                        q.push(make_pair(u, j));
                    }
                }
            }
        }
    }
    return u;
}

int main()
{
    int n1;
    int n2;
    cin >> n1 >> n2;
    cout << primeSteps(n1, n2) << endl;
}

// class Solution{   
//   public:
    
//     vector<int> prime;
    
//     Solution()
//     {
//         int mxp=9999;
//         prime=vector<int>(10001,1);
//         prime[1]=0;
//         //Seive Of Eratosthenes
//         for(int i=2;i<=mxp;i++)
//         {
//             if(prime[i])
//             {
//             for(int j=2;j*i<=mxp;j++)
//                 prime[j*i]=0;
//             }
//         }
//     } 

//     int bfs(int source,int &destination)
//     {
//         vector<int> dp(10001,-1); //stores the shotest distance from source to destination
//         vector<int> vis(10001); 
//         queue<int> q;
//         q.push(source);
//         dp[source]=0;
//         vis[source]=0;
//         while(!q.empty())
//         {
//             int current=q.front();
//             q.pop();
//             if(vis[current])
//                 continue;
//             vis[current]=1;
//             string s=to_string(current);
//             for(int i=0;i<4;i++)
//             {
//                 for(char ch='0';ch<='9';ch++)
//                 {
//                     if(ch==s[i]||(ch=='0'&&i==0))
//                         continue;
//                     string nxt=s;
//                     nxt[i]=ch;
//                     int nxtN=stoi(nxt);
//                     if(prime[nxtN]&&dp[nxtN]==-1)
//                     {
//                         dp[nxtN]=1+dp[current];
//                         q.push(nxtN);
//                     }
//                 }
//             }
//         }
//         return dp[destination];
//     }
    
//     int shortestPath(int Num1,int Num2)
//     {   
//         return bfs(Num1,Num2);
//     }
// };