class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> answer;

        for(int a:arr){
            answer[a]++;
        }
        
        int lucky = -1;

     for(pair<int, int> a:answer){
        if(a.first==a.second){
            lucky=max(lucky,a.first);
        }
     }
     return lucky;
     
    }
};