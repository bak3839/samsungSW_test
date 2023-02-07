#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> p(2);

    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> p[0] >> p[1];

    long long res = 0;

    for (int i = 0; i < n; i++) {
        int cust = v[i] - p[0], sum = 1;
        if (cust > 0) sum += ceil((float)cust / p[1]);
        res += sum;
    }

    cout << res;

    return 0;
}