/*
<단어 변환>

문제 설명
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 
아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면,
"hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 
최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
각 단어는 알파벳 소문자로만 이루어져 있습니다.
각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
begin과 target은 같지 않습니다.
변환할 수 없는 경우에는 0를 return 합니다.

입출력 예
begin	target	words	return
"hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
"hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0
*/
/*
알고리즘 : BFS
시간 복잡도 : O(N×M)
*/ 
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // set : 단어 탐색할 때 시간 복잡도 O(1)
    unordered_set<string> wordSet(words.begin(), words.end());

    if (wordSet.find(target) == wordSet.end()) {
        return answer;
    }
    
    queue<pair<string, int>> q;
    q.push({begin, answer});
    
    while (!q.empty()) {
        string current = q.front().first;
        answer = q.front().second;
        q.pop();
        
        if (current == target) {
            return answer;
        }
        
        for (int i = 0; i < current.length(); ++i) {
            string next = current;
            for (char c = 'a'; c <= 'z'; ++c) {
                next[i] = c;
                if (wordSet.find(next) != wordSet.end()) {
                    q.push({next, answer + 1});
                    wordSet.erase(next);
                }
            }
        }
    }
    
    return answer;
}

/* Case 2: DFS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 50;
bool visited[50];

//다른 문자가 1개인지 확인하는 함수
bool check_diff(string a, string b){
  int dif_cnt =0;

  for(int i=0; i<a.size();i++){
    if(a[i]!=b[i]){
      dif_cnt++;
    }
  }
  // 다른 문자가 1개일때
  if(dif_cnt==1){
    return true;
  }
  // 다른문자가 한개가 아닐때
  return false;
}

void dfs(string begin, string target,vector<string>words,int step){
  // step이 이전에 찾은 answer보다 크면 탐색할 필요가 없다
  if(answer <= step)
    return;

  if(begin==target){
    answer = min(answer,step);
    return;
  }
  
  for(int i=0; i<words.size();i++){
    // 한개의 문자만 다르고 방문 하지 않은 단어이면 탐색 시작
    if(check_diff(begin,words[i]) && !visited[i]){
      visited[i]=true;
      // 그 단어부터 탐색을 다시 시작한다. 단계가 하나 추가되었으므로 step+1을 인자로 넘긴다.
      dfs(words[i],target,words,step+1);
      // dfs 재귀 호출하여 종료되어 여기로 돌아오면, 백트래킹 (방문 표시 해제) 하여 다음분기점부터 다시 탐색을 시작한다.
      visited[i]=false;
    }
  }
  
  return;
}

int solution(string begin, string target, vector<string> words) {
  dfs(begin,target,words,0);

  // 탐색후 target문자열을 만나지 못했을 때
  if(answer == 50)
    return 0;

  return answer;
}
*/