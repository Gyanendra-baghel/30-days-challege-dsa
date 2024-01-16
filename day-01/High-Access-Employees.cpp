class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, vector<int>> user_access_times;
        vector<std::string> result;
        
        for(int i=0; i<access_times.size(); i++) {
            string user = access_times[i][0];
            string time = access_times[i][1];
            user_access_times[user].push_back(stoi(time));
        }
        
        for(auto entry: user_access_times) {
            string employee = entry.first;
            vector<int> times = entry.second;
            sort(times.begin(), times.end());
            
            for (int j = 0; j < (times.size() - 3); j++) {
                if (times[j + 2] - times[j] <= 100) {
                    result.push_back(employee);
                    break;
                }
            }
        }
        
        return result;
    }
};