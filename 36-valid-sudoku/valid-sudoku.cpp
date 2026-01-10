class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        //checking for each row and coloumn
        for(int i = 0 ; i<n ; i++){
            unordered_map<char,bool>mp1 ;
            unordered_map<char,bool>mp2 ;
            
            for(int j = 0 ; j<n ; j++){
                char ch1  = board[i][j] ;
                char ch2  = board[j][i] ;
                // checking row - to check if duplicate find in the row
                if(ch1!='.'){
                    //alraedy visited
                    if(mp1[ch1]==true){
                        return false ; // not valid 
                    }else{
                        mp1[ch1] = true ;
                    }
                }
                //checking coloumn -  to check if the duplicate find in the coloumn
                if(ch2!='.'){
                    //alraedy visited
                    if(mp2[ch2]==true){
                        return false ;
                    }else{
                        mp2[ch2] = true ;
                    }
                }
            }
        }

        // for checking sub-grid
        vector<pair<int,int>>starting_pos = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};

        for(pair<int,int> P : starting_pos){
            unordered_map<char,bool>mp;
            for(int i = P.first ; i<P.first+3 ; i++){        
                for(int j = P.second ; j<P.second+3 ; j++){
                    char ch = board[i][j];
                    
                    if(ch!='.'){
                        if(mp[ch]==true){
                            return false;
                        }else{
                            mp[ch] = true ;
                        }
                    }      
                }   
            }
        }

        return true;
    }
};