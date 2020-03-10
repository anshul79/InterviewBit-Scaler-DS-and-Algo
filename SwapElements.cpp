vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size(), temp = A[0];
    // store the max number after 1 swap
    vector<int> vec (n+1, A[0]);
    for(int i = 2; i <= n; i++) {
        int maxi = max(temp, vec[i]);
        for(int j = i; j <= n; j += i) {
            maxi = max(maxi, A[j - 1]);
            vec[j] = max(max(vec[j], A[i - 1]), A[j - 1]);
        }
        vec[i] = maxi;
        vec[1] = max(vec[1], maxi);
    }
    int m = B.size();
    vector<int> result (m);
    for(int i = 0; i < m; i++) {
        if(B[i][1] >= 2) {
            result[i] = vec[1];
        } else if(B[i][1] == 1) {
            result[i] = vec[B[i][0]];
        } else {
            result[i] = A[B[i][0] - 1];
        }
    }
    return result;
}
