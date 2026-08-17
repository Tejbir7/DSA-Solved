int main(){
        vector<int> testing = {3,1,2};
        vector<vector<int>> soln = subsets(testing);
        for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

        return 0;
    }