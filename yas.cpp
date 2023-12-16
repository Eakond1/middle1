#include <iostream>
#include <string>
using namespace std;
string vychitanie(string one, string two);
string summa(string one, string two);
int checking(string one, string two);

int checking(string one, string two) {
    if (one.size() == two.size()) {
        if (one[0] > two[0]) {
            return 1;
        }
        if (two[0] > one[0]) {
            return 2;
        }
        else {
            return 0;
        }
    } else {
        if (one.size() > two.size()) {
            return 1;
        } else if (two.size() > one.size()) {
            return 2;
        } else {
            return 0;
        }
    }
}
bool checkingformin(string one, string two) {
    one = one.erase(0, 1);
    two = two.erase(0, 1);
    int d,c;
    bool vin;
    if(one.size() == two.size()){
        for(int i = 0; i<one.length(); i++){
            d = one[i] -'0';
            c = two[i] -'0';
            if(d>c){
                vin = true;
            }
            else
                vin = false;
        }

    }
    return vin;
}
string vychitanie(string one, string two) {
    int helper = 0;
    string result = "";
    bool addMinus = false;

    if (checking(one, two) == 2) {
            if(one[0] == '-' && two[0] == '-'){
                    two = two.erase(0, 1);
                    one = one.erase(0, 1);
                    result = vychitanie(two, one);
                    return result;
            }
        result = vychitanie(two, one);
        result = "-" + result;
        return result;
    }
    bool van;
    if (one[0] == '-' && two[0] != '-') {
        one = one.erase(0, 1);
        result = summa(one, two);
        result = "-" + result;
        return result;
    } else if (one[0] != '-' && two[0] == '-') {
        two = two.erase(0, 1);
        result = summa(one, two);
        return result;
    } else if (one[0] == '-' && two[0] == '-') {
        van = checkingformin(one, two);
        if(van == true){
            one = one.erase(0, 1);
            two = two.erase(0, 1);
            result = vychitanie(one, two);
            result = "-" + result;
            return result;
        }
        else if(van == false){
            one = one.erase(0, 1);
            two = two.erase(0, 1);
            result = vychitanie(two,one);
            return result;
        }
    }

    while (one.length() < two.length()) {
        one = "0" + one;
    }
    while (two.length() < one.length()) {
        two = "0" + two;
    }
    for (int i = one.length() - 1; i >= 0; i--) {
        int digit1 = one[i] - '0';
        int digit2 = two[i] - '0';
        int diff = digit1 - digit2 - helper;
        if (diff < 0) {
            diff += 10;
            helper = 1;
        } else {
            helper = 0;
        }
        result = to_string(diff) + result;
    }
    result.erase(0, result.find_first_not_of('0'));
    if (result.empty()) {
        return "0";
    }
    if (addMinus) {
        if (result[0] == '-' && result[1] == '-') {
            result.erase(0, 1);
        } else {
            result = "-" + result;
        }
    }
    return result;
}


string summa(string one, string two) {
    int helper = 0;
    string result = "";
    bool addMinus = false;

    if (two[0] == '-' && one[0] != '-') {
        two = two.erase(0, 1);
        result = vychitanie(one, two);
        return result;
    } else if (one[0] == '-' && two[0] != '-') {
        one = one.erase(0, 1);
        result = vychitanie(two, one);
        return result;
    } else if (one[0] == '-' && two[0] == '-') {
        one = one.erase(0, 1);
        two = two.erase(0, 1);
        addMinus = true;
    }

    int i = one.length() - 1;
    int j = two.length() - 1;

    while (i >= 0 || j >= 0 || helper) {
        int sum = helper;
        if (i >= 0) {
            sum += one[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += two[j] - '0';
            j--;
        }
        helper = sum / 10;
        result = to_string(sum % 10) + result;
    }
    if (addMinus) {
        result = "-" + result;
    }
    return result;
}

void calculating(string one, string two, string sign) {
    if (sign == "1") {
        cout << summa(one, two);
    } else if (sign == "2") {
        cout << vychitanie(one, two);
    }
}

int main() {
    string one, two, sign;
    cin >> one>>two>>sign;
    calculating(one, two, sign);
    return 0;
}
