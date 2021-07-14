class Solution {
public:
    void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
				vector<int>& subset, int index)
    {
        res.push_back(subset);
        for (int i = index; i < A.size(); i++) {
            if (i != index && A[i] == A[i-1])
                continue;

            // include the A[i] in subset.
            subset.push_back(A[i]);

            // move onto the next element.
            subsetsUtil(A, res, subset, i + 1);

            // exclude the A[i] from subset and triggers
            // backtracking.
            subset.pop_back();
        }

        return;
    }

    // below function returns the subsets of vector A.
    vector<vector<int> > subsetsWithDup(vector<int>& A)
    {
        vector<int> subset;
        vector<vector<int> > res;
        
        sort(A.begin(), A.end());

        // keeps track of current element in vector A;
        int index = 0;
        subsetsUtil(A, res, subset, index);

        return res;
    }
};
