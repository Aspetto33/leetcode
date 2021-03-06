class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(backtrack(board,word,i,j,0)) return true;
            }
        }
        return false;
    }

private:
    int row;
    int col;

    bool backtrack(vector<vector<char>>& board,string word,int i,int j,int index){
        if(i>=row || i<0 || j>=col || j<0 || board[i][j]!=word[index]) return false;
        if(index == word.size()-1) return true;

        board[i][j] = ' ';
        bool result = backtrack(board,word,i+1,j,index+1)||backtrack(board,word,i-1,j,index+1) 
            ||backtrack(board,word,i,j+1,index+1)||backtrack(board,word,i,j-1,index+1);
        board[i][j] = word[index];

        return result;    
    }
};