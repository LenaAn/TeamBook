#include <bits/stdc++.h>

#define loop(i,n) for(int i=0;i<n;i++)

using namespace std;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__;

int main() {
    int n, k;
    std::cin >> n;
    std::cin >> k;

    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true); // fill k bits


    do {
        vector<int> iter;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                // addd v[i] tp item 
            }
        }
        // do logic with iter
    } while (std::next_permutation(v.begin(), v.end()));

    cout << ans << endl; 
    return 0;
}