#include<bits/stdc++.h>
using namespace std;
int f(int i,int j, int par0, int par1,const vector<int>& demand, array<int,2> fuel){

    int temp = demand[i]-fuel[j];
    if(temp<0) return -1;
    fuel[j] = temp;

    int t1=0, t2 =0, t3=0;
    if(par0 && demand[i+1]-fuel[0]>=0){
        t1 = f(i+1,0,0,par1,demand,fuel);
    }

    if(par1 && demand[i+1]-fuel[1]>=0){
        t2 = f(i+1,1,par0, 0, demand,fuel);
    }

    if(!par1 && !par0){
        int x = f(i+1,0,0,par1,demand,fuel);
        int y = f(i+1,1,par0,0,demand,fuel);

        if(x!= -1 && y!= -1) t3 = demand[i-1] + min(x,y);
        if(x==-1) t3 = demand[i-1] + y;
        else t3 = demand[i-1] +x;
    }
    return t3;
}

  int minMaxWaitingTime(vector<int>& demand, const vector<int>& g) {
        array<int,2> fuel;
        fuel[0] = g[0];
        fuel[1] = g[1];

        return min(f(0,0,0,1,demand,fuel),f(0,1,1,0,demand,fuel));       
    }