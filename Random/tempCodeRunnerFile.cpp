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

    vector<double> marks(n);
    double sum = 0;
    cout << "Enter marks of Students: ";
    for (int i = 0; i < n; ++i) {
        cin >> marks[i];
        sum += marks[i];
    }

    // 1. Calculating Mean (mu) - The average performance
    double mu = sum / n;

    // 2. Calculating Standard Deviation (sigma) - The spread of marks
    double varianceSum = 0;
    for (double m : marks) {
        varianceSum += pow(m - mu, 2);
    }
    double sigma = sqrt(varianceSum / n);

    cout << "\n--- Class Stats ---" << endl;
    cout << "Mean (Average): " << mu << endl;
    cout << "Standard Deviation: " << sigma << endl;
    cout << "-------------------\n" << endl;

    
    // Absolute CEILINGS/CAPS from college 
    const int S_CAP = 90; 
    const int A_CAP = 80;
    const int B_CAP = 70;
    const int C_CAP = 60;
    const int D_CAP = 50;
    const int E_MIN = 40;

    // 3. Applying Statistical Formulas (Bell Curve)
    // S >= Mean + 1.5*Sigma
    // A >= Mean + 1.0*Sigma
    // B >= Mean + 0.5*Sigma
    // C >= Mean
    // D >= Mean - 0.5*Sigma
    
    int S = min((int)round(mu + 1.5 * sigma), S_CAP);
    int A = min((int)round(mu + 1.0 * sigma), A_CAP);
    int B = min((int)round(mu + 0.5 * sigma), B_CAP);
    int C = min((int)round(mu), C_CAP);
    int D = min((int)round(mu - 0.5 * sigma), D_CAP);

    //Ensuring boundaries don't overlap
    A = min(A, S - 1);
    B = min(B, A - 1);
    C = min(C, B - 1);
    D = max(E_MIN, min(D, C - 1));

    // FINAL OUTPUT 
    cout << "The S grade would be >= " << S << endl;
    cout << "The A grade would be >= " << A << " and < " << S << endl;
    cout << "The B grade would be >= " << B << " and < " << A << endl;
    cout << "The C grade would be >= " << C << " and < " << B << endl;
    cout << "The D grade would be >= " << D << " and < " << C << endl;
    
    if (D > E_MIN) 
        cout << "The E grade would be >= 40 and < " << D << endl;
    else
        cout << "The E grade is fixed at 40 (Merged with D range)\n";

    cout << "The U grade is less than 40\n";
    return 0;
}