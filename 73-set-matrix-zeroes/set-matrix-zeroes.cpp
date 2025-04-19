class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
         if (n == 0) return;
        int m = matrix[0].size(); //columns
         if (m == 0) return;

        vector<int> row(n, 0);        // don't use int row[n] = {0}; 
        vector<int> col(m, 0);

//mark rows & columns to be made zero
        for(int i=0; i<n; i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // make the rows and columns zero
        for(int i=0; i<n; i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }


    }
};