class Solution {
public:
    vector<vector<int>> memoArray;
    int minDifficultyUtil(vector<int>& jobDifficulty, int numJobs, int curr, int cut) {
        if(memoArray[curr][cut] != -1) return memoArray[curr][cut];
        if(curr == 1) {
            int max_temp = INT_MIN;
            for(int i = cut; i < numJobs; i++) max_temp = max(max_temp, jobDifficulty[i]);
            return memoArray[curr][cut] = max_temp;
        }
        
        int maxDiff = 0;
        int res = INT_MAX;
        for(int j = cut; j < numJobs-curr+1; j++) {
            maxDiff = max(maxDiff, jobDifficulty[j]);
            res = min(res, maxDiff + minDifficultyUtil(jobDifficulty, numJobs, curr-1, j+1));
        }
        
        return memoArray[curr][cut] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int numJobs = jobDifficulty.size();
        if(numJobs < d) return -1;
        memoArray.assign(numJobs+1, vector<int>(numJobs+1, -1));
        
        return minDifficultyUtil(jobDifficulty, numJobs, d, 0);
    }
};