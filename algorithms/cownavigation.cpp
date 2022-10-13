//created by Oleksandr Gorpynich
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int n;
struct state{
	int x1;
	int y1;
	int x2;
	int y2;
	int dir;
	int dist;
};
char arr[21][21];
int visited[21][21][21][21][4];
//x1, y1, x2, y2, dir
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
//up, left, down, right
//test if a cell is possible to visit
bool inside(int x, int y){
	if (x >= 0 && x < n && y >= 0 && y < n){
		if (arr[x][y] != 'H'){
			return true;
		}
	}
	return false;
}
//set a state as visited
bool setvisited(state cur){
	visited[cur.x1][cur.y1][cur.x2][cur.y2][cur.dir] = 1;
}
//check if a state has been visited
bool free(state cur){
	if (visited[cur.x1][cur.y1][cur.x2][cur.y2][cur.dir] == -1){
		return true;
	}
	return false;
}
int main(){
	ifstream in("cownav.in");
	ofstream out("cownav.out");
	in >> n;
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			in >> arr[x][y];
		}
	}
	memset(visited, -1, sizeof visited);
	queue<state> q;
	q.push({n - 1, 0, n - 1, 0});
	while(q.size() > 0){
		state cur = q.front();
		q.pop();
		state ncur = cur;
		bool reachedend1 = false;
		bool reachedend2 = false;
		//check if reached the end
		if (cur.x1 == 0 && cur.y1 == n - 1){
			reachedend1 = true;
		}
		if (cur.x2 == 0 && cur.y2 == n - 1){
			reachedend2 = true;
		}
		if (reachedend1 && reachedend2){
			out << ncur.dist << "\n";
			return 0;
		}
		//turn clockwise
		ncur = cur;

		ncur.dir = (cur.dir + 1) % 4;
		ncur.dist += 1;
		if (free(ncur)){
			setvisited(ncur);
			q.push(ncur);
		}
		//turn counter clockwise
		ncur = cur;
		ncur.dir = (cur.dir - 1) == -1?3:(cur.dir - 1);
		ncur.dist += 1;
		if (free(ncur)){
			setvisited(ncur);
			q.push(ncur);
		}
		//go forward
		ncur = cur;
		if (inside(ncur.x1 + dx[ncur.dir], ncur.y1 + dy[ncur.dir]) && !reachedend1){
			ncur.x1 += dx[ncur.dir];
			ncur.y1 += dy[ncur.dir];
		}
		if (inside(ncur.x2 + dx[(ncur.dir + 1) % 4], ncur.y2 + dy[(ncur.dir + 1) % 4]) && !reachedend2){
			ncur.x2 += dx[(ncur.dir + 1) % 4];
			ncur.y2 += dy[(ncur.dir + 1) % 4];
		}
		ncur.dist += 1;
		if (free(ncur)){
			setvisited(ncur);
			q.push(ncur);
		}
	}
	out << -1 << "\n";
}