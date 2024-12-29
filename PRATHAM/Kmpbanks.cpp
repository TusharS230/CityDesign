#include <iostream>
#include <vector>
#include <string>

using namespace std;

void KMPSearch(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();

    vector<int> lps(m, 0);

    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
            lps[i] = j;
        }
    }

    j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
            if (j == m) {
                cout << "Pattern found at index " << i - m + 1 << endl;
                j = lps[j - 1];
            }
        }
    }
}

int main() {
    string text = "Customer transaction history: Deposit, Withdrawal, Transfer";
    string pattern = "Withdrawal";

    KMPSearch(text, pattern);

    return 0;
}
