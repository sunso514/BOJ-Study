#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

#define MAX 50001 // 최대 정점의 개수
#define INF 99999999

//    vector<int> list(time);
//vector<int> list;


int nd, edg, a, b, val, res;
vector<int> graph(MAX);

//vector<vector<int>> vec;

struct Node {
    int next, distance;
    Node(int a, int b) {
        next = a;
        distance = b;
    }
};

vector<Node> arr[MAX];

struct compare {
    bool operator()(Node& i, Node& j) {
        return i.distance > j.distance;
    }
};

void dijkstra(int start) {
    //시작 지점 넣기
    graph[start] = 0;
    priority_queue<Node, vector<Node>, compare> pq;

    pq.push(Node(start, 0));

    while (!pq.empty()) {
        //현재 위치 꺼내기
        int now = pq.top().next;
        int distance = pq.top().distance;
        pq.pop();

        if (now == nd) {
            res = distance;
            break;
        }

        //최단거리가 아닌경우 스킵
        if (graph[now] < distance) continue;

        //현재에서 이어져있는 모든 노드 호출
        for (int i = 0; i < arr[now].size(); i++) {
            //선택된 노드의 인접노드
            int next = arr[now][i].next;

            //선택된 노드를 인접 노드로 거쳐서 가는 비용
            int nextDistance = distance + arr[now][i].distance;

            //기존의 최소 비용보다 더 저렴하다면 교체
            if (nextDistance < graph[next]) {
                graph[next] = nextDistance;
                pq.push(Node(next, nextDistance));
            }
        }
    }

    cout << res;

}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> nd >> edg;
    for (int i = 1; i <= nd; i++) {
        graph[i] = 987654321;
    }
    for (int i = 0; i < edg; i++) {
        cin >> a >> b >> val;
        arr[a].push_back({ b,val });
        arr[b].push_back({ a,val });
    }
    priority_queue<Node, vector<Node>, compare> pq;
    dijkstra(1);






}