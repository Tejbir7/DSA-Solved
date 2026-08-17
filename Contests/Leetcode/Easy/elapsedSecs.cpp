#include<bits/stdc++.h>
using namespace std;
int secondsBetweenTimes(string startTime, string endTime) {
       int startHr = stoi(startTime.substr(0, 2));
int endHr   = stoi(endTime.substr(0, 2));

int startMin = stoi(startTime.substr(3, 2));
int endMin   = stoi(endTime.substr(3, 2));

int startSec = stoi(startTime.substr(6, 2));
int endSec   = stoi(endTime.substr(6, 2));

        int ans  = endSec- startSec;
        ans += (endMin-startMin) * 60;
        ans += (endHr-startHr) * 3600;
        
        return ans;
    }