#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    vector<int> sums;
    vector<vector<int>> filledVector;
    
    // vector par z ktorych powstaja przedziały
    vector<std::pair<int, int>> intervals2 = {{1,5},{4, 10}};
    
    // tworzymy vektor ktory posiada wektory uzupelnione liczbami calkowitymi od [i].first do i[second]
    for(int i=0; i<intervals2.size(); ++i){
        
        vector<int> v1={};
        
        for(int j=intervals2[i].first; j<=intervals2[i].second; ++j ){
            v1.push_back(j);
        }
        
        filledVector.push_back(v1);
    }
    
    for(int i=0; i<filledVector.size(); ++i){
        for(int j=0; j<filledVector[i].size(); ++j){
            cout << filledVector[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<int> repeats{};
    vector<int> whole{};

    for (auto i = filledVector[0].begin(); i != filledVector[0].end(); ++i)
    {
        if (std::find(filledVector[1].begin(), filledVector[1].end(), *i) != filledVector[1].end())
        {
            repeats.push_back(*i);
        }
    }
    cout << endl;
    
    if(repeats.size() > 0){
        
        for(int i=0; i<intervals2.size(); ++i){
            whole.push_back(intervals2[i].first);
            whole.push_back(intervals2[i].second);
        }
        
        sort(whole.begin(),whole.end());
        vector<int> result;
        
        for(int i=whole[0]; i<=whole[whole.size()-1]; ++i){
            result.push_back(i);
            
        }
        
        for(auto &e : result){
            cout << e << " ";
        }
    }


    return 0;
}
