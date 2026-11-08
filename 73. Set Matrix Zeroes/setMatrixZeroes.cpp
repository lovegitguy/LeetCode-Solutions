class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> ZeroRows;
        vector<int> OneColumns;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){

                if(matrix[i][j]==0){
                        ZeroRows.push_back(i);
                        OneColumns.push_back(j);
                }
            }

        }

        for(int rows:ZeroRows){
                for(int j=0;j<matrix[rows].size();j++){
                    matrix[rows][j]=0;
                }
            }

            for(int col:OneColumns){
                for( int i=0;i<matrix.size();i++){
                    matrix[i][col]=0;
                }
            }
    }
};