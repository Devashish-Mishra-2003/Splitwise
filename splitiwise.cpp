#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void minimizeCashFlow(vector<int>& netAmount, vector<string>& names) {
    int n = netAmount.size();

    while (true) {

        int maxCredit = max_element(netAmount.begin(), netAmount.end()) - netAmount.begin();
        int maxDebit = min_element(netAmount.begin(), netAmount.end()) - netAmount.begin();

        if (netAmount[maxCredit] == 0 && netAmount[maxDebit] == 0)
            break;

        int minAmount = min(-netAmount[maxDebit], netAmount[maxCredit]);

        netAmount[maxCredit] -= minAmount;
        netAmount[maxDebit] += minAmount;

        cout << names[maxDebit] << " pays " << minAmount
             << " to " << names[maxCredit] << endl;
    }
}

void splitwise(vector<vector<int>>& transactions, vector<string>& names, int n) {
    vector<int> netAmount(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            netAmount[i] += (transactions[j][i] - transactions[i][j]);
        }
    }

    minimizeCashFlow(netAmount, names);
}

int main() {
    int n;
    cout << "Enter the number of people : ";
    cin >> n;
    cin.ignore();

    vector<string> names(n);
    cout << "Enter the names of the people :\n";
    for (int i = 0; i < n; i++) {
        cout << "Person " << i + 1 << ": ";
        getline(cin,names[i]);
    }

    vector<vector<int>> transactions(n, vector<int>(n, 0));

    cout << "\nEnter the transactions\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i!=j){
            cout << names[i] << " owes " << names[j] << " : ";
            cin >> transactions[i][j];
            }
        }
    }

    cout << "\nMinimized transactions :\n";
    splitwise(transactions, names, n);

    return 0;
}