#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl
#define fr freopen("in.txt", "r", stdin);
#define fw freopen("out.txt", "w", stdout);
#define mem(x) memset((x), 0, sizeof((x)));

 int sum_of_digits(string num){
    int temp = 0;
    for(int i = 0; i < num.length(); i++) temp += (num[i]-'0');
    //debug(temp);
    int number = temp;
    while(temp > 9){
        //debug(temp);
        temp = 0;
        while(number != 0){
            temp += (number%10);
            number/=10;
            //debug(number);
        }
        number = temp;
    }
    return temp;
}

int main(){
    string str;
    while((cin >> str)){
        if(str == "0") break;
        int result = sum_of_digits(str);
        printf("%d\n", result);
    }
    return 0;
}
