//美式足球，每场可以得2，3，6或者1分，而且得了6分之后才能得1分。给一个分数求多少种取得的方法。注意：如果是5分，[2, 3]和[3, 2]是不同的方式。不算难的dp
int sorcer(int n){
    vector<int> DP(target+1, 0);
    vector<int> pre6(target+1, 0);
    DP[0] = 1;
    DP[2] = 1;
    DP[3] = 1;
    pre6[0] = 1;
        
    for(int i=4; i<=5; ++i){
        DP[i] = DP[i-2]+DP[i-3];
    }
    for(int i=6; i<=target; ++i){
        DP[i] = DP[i-2]+DP[i-3]+DP[i-6]+pre6[i-1];
        pre6[i] = DP[i-6];
    }
}