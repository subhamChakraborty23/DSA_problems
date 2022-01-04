#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;
class Solution {
    //Node -> {score , (x, y)}
    
public:
    int maxPathSum(vector<vector<int > > &grid,int startCol)
    {   
        
        int dy[3] = {1, 0, -1};
        int res = 0;
        int row = grid.size(),col = grid[0].size();
        vector<pair<int,pair<int,int> > >path;
        priority_queue<pair<int,pair<int,int> > > pq;
        pq.push(make_pair(grid[0][startCol],make_pair(0,startCol)));

        while(!pq.empty())
        {
            int score = pq.top().first;
            
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            path.push_back(make_pair(score,make_pair(x,y)));//the top one is the one with max score
            pq.pop();
            while(!pq.empty())
            {
                pq.pop();
            }
            for(int i = 0;i<3;i++)
            {
                int nx = x + 1;
                int ny = y + dy[i];
                if(nx>=0 && nx<row && ny>=0 && ny<col)
                {
                    pq.push(make_pair(grid[nx][ny],make_pair(nx,ny)));
                }
            }
        }

        for(int i=0;i<path.size();i++)
        {
            cout<<"{"<<path[i].second.first<<" "<<path[i].second.second<<" "<<path[i].first<<"}"<<endl;
            res+=path[i].first;
        }
        cout<<endl;

        return res;

    }
};

int main(){
    vector<vector<int > > grid;
    int arr[][6] = { { 10, 10, 2, 0, 20, 4 },

                    { 0, 0, 0, 30, 2, 5 },

                    { 41, 10, 4, 0, 2, 0 },

                    { 1, 0, 2, 20, 0, 4 } };
    for(int i=0;i<4;i++){
        vector<int> temp;
        for(int j=0;j<6;j++){
            temp.push_back(arr[i][j]);
        }
        grid.push_back(temp);
    }
    Solution s;
    cout<<s.maxPathSum(grid,1)<<endl;
    return 0;


}