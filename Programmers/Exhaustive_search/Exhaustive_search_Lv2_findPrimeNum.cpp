/*
<소수 찾기>

문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

입출력 예
numbers	return
"17"	3
"011"	2
*/
// Case 1
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int num){
    if (num < 2) return false; // 0과 1은 소수가 아님
    for(int i = 2; i  <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

void findCombinations(string s, string current, set<int> &unique_combinations) {
    if (!current.empty()) {
        int num = stoi(current);
        unique_combinations.insert(num);
    }
    
    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        s.erase(i, 1);
        findCombinations(s, current + ch, unique_combinations);
        s.insert(i, 1, ch); // 원래의 문자열로 복구
    }
    /* ex) when s = "123" 
    1. i = 0: '1'을 선택하고 s에서 제거 -> s는 "23"
    재귀 호출: findCombinations("23", "1", ...)
        1.1 i = 0: '2'를 선택하고 s에서 제거 -> s는 "3"
        재귀 호출: findCombinations("3", "12", ...)
            1.1.1 i = 0: '3'을 선택하고 s에서 제거 -> s는 ""
            재귀 호출: findCombinations("", "123", ...)
                1.1.2 '3'을 s에 복구 -> s는 "3"
                1.1.3 '2'을 s에 복구 -> s는 "23"
        1.2 i = 1: '3'을 선택하고 s에서 제거 -> s는 "2"
        재귀 호출: findCombinations("2", "13", ...)
            1.2.1 i = 0: '2'를 선택하고 s에서 제거 -> s는 ""
            재귀 호출: findCombinations("", "132", ...)
                1.2.2 '2'를 s에 복구 -> s는 "2"
        1.3 '2'와 '3'을 s에 복구 -> s는 "23"
    2. i = 1: '2'을 선택하고 s에서 제거 -> s는 "13"
    재귀 호출: findCombinations("13", "2", ...)
    (이하 생략)
    3. i = 2: '3'을 선택하고 s에서 제거 -> s는 "12"
    재귀 호출: findCombinations("12", "3", ...)
    (이하 생략)
    */
}


int solution(string numbers) {
    int answer = 0;
    set<int> unique_combinations; // 중복 제거를 위한 set
    findCombinations(numbers, "",unique_combinations);
    
    for (int number : unique_combinations) {
        if (isPrime(number)) answer += 1;
    }
    
    return answer;
}

/* Case 2 순열 내장함수 사용 버전
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm> // next_permutation을 사용하기 위함

using namespace std;

bool isPrime(int num){
    if (num < 2) return false; // 0과 1은 소수가 아님
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> unique_combinations; // 중복 제거를 위한 set

    sort(numbers.begin(), numbers.end());

    do {
        for(int i = 1; i <= numbers.length(); ++i) {
            int num = stoi(numbers.substr(0, i));
            unique_combinations.insert(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    for (int number : unique_combinations) {
        if (isPrime(number)) answer += 1;
    }

    return answer;
}

*/