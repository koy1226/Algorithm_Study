/*
Practice Link: https://softeer.ai/practice/6293
*/
#include "Common.h"

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int* A = new int[N];
    int* LIS = new int[N];
    int idx = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int j = 0; j < N; j++) {
        if (idx == 0) LIS[idx++] = A[j];
        else {
            if (LIS[idx - 1] < A[j])  LIS[idx++] = A[j];
            else {
                LIS[lower_bound(LIS, LIS + idx, A[j]) - LIS] = A[j];
            }
        }
    }

    cout << idx;

    delete[] A;
    delete[] LIS;

    return 0;
}
/*
Case 2 : BinarySearch
#include<iostream>
#include<vector>

using namespace std;

vector<int> lis;
int binarysearch(int left, int right, int target) {

	int mid;

    // lis 배열에 들어갈 target=arr[i]의 위치를 이분탐색으로 찾기

	while (left < right) {
		mid = (left + right) / 2; // 중간값 설정

		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  lis.push_back(arr[0]);
  int length = 1;

  for (int i = 1; i < N; i++) {
    if (lis[length - 1] < arr[i]) {
      lis.push_back(arr[i]);
      length++;
    } else {
      int idx = binarysearch(0, length - 1, arr[i]);
      lis[idx] = arr[i];
    }
  }

  cout << length << endl;
  
   return 0;
}
*/
