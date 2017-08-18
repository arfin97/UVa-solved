//https://www.urionlinejudge.com.br/judge/en/problems/view/1279
//Verdict: 10% Wrong.

#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl
#define fr freopen("in.txt", "r", stdin);
#define fw freopen("out.txt", "w", stdout);
using namespace std;

bool divisible_by_eleven(string num){
    int sum = 0;
    for(int i = 0; i < num.length(); i++){
        int digit = num[i]-'0';
        if(i%2 == 1) digit = digit*-1;
        sum += digit;
        //debug(sum);
    }
    if(sum%11 == 0){
        return true;
    }
    else{
        return false;
    }
}

bool divisible_by_three(string num){
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
    if(temp%3 == 0) return true;
    else return false;
}

int main(){
//    fr;
//    fw;
    string num;
    int first = 1;
    while(cin >> num){
        if(first == 0){
            printf("\n");
        }
        first = 0;
        //Divisibility Checks;
        bool four = false;
        bool hundread = false;
        bool four_hundread = false;
        bool eleven = false;
        bool five = false;
        bool three = false;

        int digit1;
        int digit2;
        int digit3;
        int number;
        //For four
        if(num.length() == 1){
            digit1 = (num[num.length()-1]-'0');
            if(digit1%3 == 0) three = true;
            if(digit1%4 == 0) four = true;
            if(digit1%5 == 0) five = true;
        }
        if(num.length() == 2){
            digit1 = (num[num.length()-1]-'0');
            digit2 = (num[num.length()-2]-'0');
            number = digit2 * 10 + digit1;

            if(number%3 == 0) three = true;
            if(number%4 == 0) four = true;
            if(number%5 == 0) five = true;
            if(number%11 == 0) eleven = true;
        }
        if(num.length() == 3){
            digit1 = (num[num.length()-1]-'0');
            digit2 = (num[num.length()-2]-'0');
            digit3 = (num[num.length()-3]-'0');
            number = digit3 * 100 + digit2 * 10 + digit1;

            if(number%3 == 0) three = true;
            if(number%4 == 0) four = true;
            if(number%5 == 0) five = true;
            if(number%11 == 0) eleven = true;
            if(number%100 == 0) hundread = true;
            if(number%400 == 0) four_hundread = true;
        }

        if(num.length() >= 4){
            if(num[num.length()-1] == '0' && num[num.length()-2] == '0'){
                hundread = true;
                five = true;
                digit1 = (num[num.length()-3]-'0');
                digit2 = (num[num.length()-4]-'0');
                number = digit2 * 10 + digit1;
                if(number%4 == 0){
                    four_hundread = true;
                    four = true;
                }
            }
            else{
                digit1 = (num[num.length()-1]-'0');
                digit2 = (num[num.length()-2]-'0');
                number = digit2 * 10 + digit1;

                if(number%4 == 0) four = true;
                if(number%5 == 0) five = true;
            }

            eleven = divisible_by_eleven(num);
            three = divisible_by_three(num);
        }

//        //
//        debug(three);
//        debug(four);
//        debug(five);
//        debug(eleven);
//        debug(hundread);
//        debug(four_hundread);
//        //

        //Leap Year test
        bool ordinary_year = true;
        bool leap_year = false;
        if(four == true){
            if(hundread == true){
                if(four_hundread == true){
                    printf("This is leap year.\n");
                    leap_year = true;
                }
            }else{
                printf("This is leap year.\n");
                leap_year = true;
            }
            ordinary_year = false;
        }
        //Huluchulu test
        if(five == true && three == true){
            printf("This is huluculu festival year.\n");
            ordinary_year = false;
        }
        //Bukuluchu test
        if(leap_year == true && five == true && eleven == true){
            printf("This is bulukulu festival year.\n");
            ordinary_year = false;
        }

        if(ordinary_year == true){
            printf("This is an ordinary year.\n");
        }
    }
    return 0;
}
