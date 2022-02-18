#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    int counter = 1;
    int indexAns = 0;
    vector<int> h_index (citations_per_paper.size());
    
    // TODO: Calculate and return h-index score for each paper.
    sort(citations_per_paper.begin(), citations_per_paper.end());
    
    if(citations_per_paper[0] >= counter) {
        h_index[indexAns] = counter;
        counter++;
        indexAns++;
    }
    
    for (auto itr = citations_per_paper.begin() + 1; itr != citations_per_paper.end(); itr++) {
        auto itr_start = itr - (counter - 1);
        
        if (*itr_start >= counter) {
            h_index[indexAns] = counter;
            counter++;
        }
        
        else
            h_index[indexAns + 1] = h_index[indexAns];
        
        indexAns++;
    }
    
    return h_index;
}

int main() {
    int tests;
    cin >> tests;
    
    for (int test_case = 1; test_case <= tests; test_case++) {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++)
            cin >> citations[i];
    
        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
    
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << " ";
        cout << endl;
    }
    return 0;
}