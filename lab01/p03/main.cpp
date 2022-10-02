#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const string noDataMessage = "no data";
    const int columnWidth = 30;

    for (string name; cin >> name;)
    {
        int nGrades = 0;
        double sum = 0;
        for (int grade; cin >> grade;)
        {
            ++nGrades;
            sum += grade;
        }
        cout << setfill('.') << fixed << setprecision(2);
        if (nGrades != 0)
        {
            cout << left << setw(columnWidth) << name << "|" << right << setw(columnWidth) << sum / nGrades << "\n";
        }
        else
        {
            cout << left << setw(columnWidth) << name << "|" << right << setw(columnWidth) << noDataMessage << "\n";
        }
        cin.clear();
    }
}