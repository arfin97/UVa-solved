#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl
#define fr freopen("in.txt", "r", stdin);
#define fw freopen("out.txt", "w", stdout);
#define mem(x) memset((x), 0, sizeof((x)));

//Compare Function for more flexibility in sorting.
bool sortbysec(const pair<string,int> &a, const pair<string,int> &b){
    return (a.second > b.second);
}

int main(){
    int tc;
    scanf("%d", &tc);
    for(int tr = 1; tr <= tc; tr++){
        //Declaring vector to store pairs
        vector< pair<string, int> > sites;
        //Inputting data using push_back(make_pair());
        for(int i = 0; i < 10; i++){
            string str;
            int num;
            cin >> str >> num;
            sites.push_back(make_pair(str, num));
        }
        //Stable sorting
        stable_sort(sites.begin(), sites.end(), sortbysec);
// For printing purpose.
//        for(int i = 0; i < 10; i++){
//            cout << i+1 << "-" << sites[i].second << " ";
//            cout << sites[i].first << endl;
//        }

        //Making another pair vector to store result
        vector< pair<string, int> > result;
        int most = sites[0].second;
        int i = 0;
        //Getting the most rated sites out.
        while(sites[i].second == most){
            result.push_back(sites[i]);
            i++;
        }
        printf("Case #%d:\n", tr);
        //Printing the result vector.
        for(int i = 0; i < result.size(); i++){
            cout << result[i].first << endl;
        }

    }
    return 0;
}
