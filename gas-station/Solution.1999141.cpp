class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int tryMax = 0, theMax = 0, tryMaxIdx = 0, maxIdx = 0, myGas = 0;
        for(int i = 0; i < 2 * gas.size(); i++ ){
            if(tryMax == 0)
                tryMaxIdx = i;
            tryMax = tryMax + gas[i] - cost[i] > 0 ? tryMax + gas[i] - cost[i] : 0;
            if(tryMax > theMax){
                maxIdx = tryMaxIdx;
                theMax = tryMax;
            }
        }
        
        maxIdx = maxIdx % gas.size();
        for(int i = 0; i < gas.size(); i++ ){
            int idx = (i + maxIdx) % gas.size();
            myGas = myGas + gas[idx] - cost[idx];
            if(myGas < 0) return -1;
        }
        
        return maxIdx;
    }
};