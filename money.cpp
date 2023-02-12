#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int N, ans;

void work(int d, int sum) {
    for (int i = d; i < N; i++) {
        int time = v[i].first;
        int money = v[i].second;

        if (i + time <= N) {
            work(i + time, sum + money);
        }

        else ans = max(ans, sum);
    } 

    ans = max(ans, sum);
}

int main() {
    int a, b;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    for (int i = 0; i < N; i++) work(i, 0);

    cout << ans;
    return 0;
}