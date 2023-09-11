/*
<Ÿ�� �ѹ�>
���� ����
n���� ���� �ƴ� �������� �ֽ��ϴ�. �� �������� ������ �ٲ��� �ʰ� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.

����� ��
numbers	            target	    return
[1, 1, 1, 1, 1]	    3	        5
[4, 1, 2, 1]	    4	        2
*/
#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> numbers, int target, int& answer, int count = 0, int sum = 0) {
    if (count == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    DFS(numbers, target, answer, count + 1, sum + numbers[count]);
    DFS(numbers, target, answer, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, answer);
    return answer;
}
/*
���2)
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}
*/