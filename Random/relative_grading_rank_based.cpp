#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter Class size: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid class size\n";
        return 0;
    }

    vector<int> marks(n);
    cout << "Enter marks of Students: ";
    for (int i = 0; i < n; ++i) cin >> marks[i];

    int x;
    cout << "What percentage of Class you want to score S: ";
    cin >> x;
    if (x <= 0 || x > 100) {
        cout << "Invalid percentage\n";
        return 0;
    }

    //Absolute CEILINGS, acc to absolute grading in college 
    const int S_CAP = 90; 
    const int A_CAP = 80;
    const int B_CAP = 70;
    const int C_CAP = 60;
    const int D_CAP = 50;
    const int E_MIN = 40;

    sort(marks.begin(), marks.end());

    //Relative S grading (%age based)
    int topX = max(1, (int)ceil(n * x / 100.0));
    topX = min(topX, n);
    int sIndex = n - topX;

    int S_rel = marks[sIndex];
    int S = min(S_rel, S_CAP);  

    if (topX == n) {
        cout << "The S grade would be >= " << S << endl;
        cout << "All students are S grade\n";
        cout << "The U grade is less than 40\n";
        return 0;
    }

    //Passed students below S (>=40) 
    vector<int> passed;
    for (int i = 0; i < sIndex; ++i)
        if (marks[i] >= E_MIN)
            passed.push_back(marks[i]);

    int m = passed.size();
    if (m == 0) {
        cout << "The S grade would be >= " << S << endl;
        cout << "No A to E grades (no passed students below S)\n";
        cout << "The U grade is less than 40\n";
        return 0;
    }

    //Distributing passed students into A–E by count

    vector<int> bucketSize(5, m / 5);
    int extra = m % 5;
    for (int i = 0; i < extra; ++i) ++bucketSize[i];

    //Computing RELATIVE cutoffs 
    int pos = m;
    int A_rel = -1, B_rel = -1, C_rel = -1, D_rel = -1;

    if (bucketSize[0] > 0) { pos -= bucketSize[0]; A_rel = passed[pos]; }
    if (bucketSize[1] > 0) { pos -= bucketSize[1]; B_rel = passed[pos]; }
    if (bucketSize[2] > 0) { pos -= bucketSize[2]; C_rel = passed[pos]; }
    if (bucketSize[3] > 0) { pos -= bucketSize[3]; D_rel = passed[pos]; }

    //CAPPING RELATIVE CUTS
    int A = (A_rel == -1) ? -1 : min(A_rel, A_CAP);
    int B = (B_rel == -1) ? -1 : min(B_rel, B_CAP);
    int C = (C_rel == -1) ? -1 : min(C_rel, C_CAP);
    int D = (D_rel == -1) ? -1 : min(D_rel, D_CAP);

    //FINAL OUTPUT 
    cout << "The S grade would be >= " << S << endl;

    if (A != -1) cout << "The A grade would be >= " << A << " and < " << S << endl;
    if (B != -1) cout << "The B grade would be >= " << B << " and < " << A << endl;
    if (C != -1) cout << "The C grade would be >= " << C << " and < " << B << endl;
    if (D != -1) cout << "The D grade would be >= " << D << " and < " << C << endl;
    if (D > E_MIN) cout << "The E grade would be >= 40 and < " << D << endl;

    cout << "The U grade is less than 40\n";
    return 0;
}
