#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::string find_odd_one_out(std::vector<std::string> strings) {
    std::vector<std::map<char, int>> counters;
    for (const auto& s : strings) {
        std::map<char, int> counter;
        for (char c : s) {
            counter[c]++;
        }
        counters.push_back(counter);
    }

    std::map<char, int> common_counter;
    int max_count = 0;
    for (const auto& counter : counters) {
        int count = std::count(counters.begin(), counters.end(), counter);
        if (count > max_count) {
            max_count = count;
            common_counter = counter;
        }
    }

    for (size_t i = 0; i < counters.size(); i++) {
        if (counters[i] != common_counter) {
            return strings[i];
        }
    }

    return "";
}
void func(vector<string> s){
    for(int i=0;i<s.size();i++){
        sort(s[i].begin(),s[i].end());
    }
    vector<vector<int>> v;
    for(int i=0;i<s.size();i++){
        string st = s[i];
        vector<int> ans;
        for(int i=0;i<st.size()-1;i++){
            ans.push_back((st[i+1]-st[i])%26);
        }
        v.push_back(ans);
    }   
    for(int i=0;i<v.size();i++){
        // if(v[i] == v[i+1])
        cout<<v[i]<<endl;
    }

}
int main() {
    std::vector<std::string> strings = {"ABCD", "BCDE", "EFGH", "DCBE"};
    func(strings);
    // std::cout << find_odd_one_out(strings) << std::endl;  // Output: "DCBE"
    return 0;
}