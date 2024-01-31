#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool latestTime(string var1, string var2) 
{
    tm date1, date2;
    istringstream stream1(var1);
    istringstream stream2(var2);
    stream1 >> get_time(&date1, "%d/%m/%Y#%H:%M:%S");
    stream2 >> get_time(&date2, "%d/%m/%Y#%H:%M:%S");

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    if (time1 < time2) return false;
    else return true;
}

int main()
{
    IOS;
    int t;
    cin >> t;

    map<string, pair<string, string>> emailMap;
    map<string, string> emailTimeMap;
    map<string, int> bloodMap, birthMap;

    while (t--)
    {
        string timestamp, email, birthDate, bloodGroup;
        cin >> timestamp >> email >> birthDate >> bloodGroup;

        bool Latest = true;
        if (emailTimeMap.count(email) == 0) emailTimeMap[email] = timestamp;
        else Latest = latestTime(timestamp, emailTimeMap[email]);

        if (Latest) emailMap[email] = { bloodGroup, birthDate };
    }

    for (auto &&i : emailMap)
    {
        bloodMap[i.second.first]++;
        birthMap[i.second.second.substr(6, 4)]++;
    }

    vector<pair<string, int>> birthVector;
    for (auto&& i : birthMap) birthVector.push_back(make_pair(i.first, i.second));
    sort(birthVector.begin(), birthVector.end());

    string ArrBloodGroup[] = { "A+" ,"A-" ,"AB+", "AB-", "B+" , "B-" ,"O+","O-" };
    for (auto&& i : ArrBloodGroup) cout << i << " " << bloodMap[i] << endl;
    for (auto&& i : birthVector) cout << i.first << " " << i.second << endl;
}
