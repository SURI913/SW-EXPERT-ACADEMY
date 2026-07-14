import java.util.Scanner;
import java.util.*;

class Solution
{
    static final int MAX = 16;
    static int N;
    static int map[][] = new int[MAX][MAX];

    //방향접근용
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};

    static class Node implements Comparable<Node> {
        int x;
        int y;
        int time;

        public Node(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
        @Override
        public int compareTo(Node o) {
            return this.time - o.time;
        }
    }
    static int bfs(int sx, int sy, int ex, int ey) {
        PriorityQueue<Node> q = new PriorityQueue<>();
        boolean visited[][][] = new boolean[N][N][3];
        q.offer(new Node(sx, sy, 0)); // 시작점 큐에 넣기 add는 반환이 false면 offer는 반환이 false면 예외발생
        visited[sx][sy][0] = true;

        while (!q.isEmpty()) {
            Node current = q.poll();

            if (current.x == ex && current.y == ey) {
                return current.time;
            }

            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                int nt = current.time + 1;

                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;

                if (map[nx][ny] == 1)
                    continue;

                // 소용돌이
                if (map[nx][ny] == 2) {
                    if (nt % 3 != 2) {
                        // 기다리기
                        if (!visited[current.x][current.y][nt % 3]) {
                            visited[current.x][current.y][nt % 3] = true;
                            q.offer(new Node(current.x, current.y, nt));
                        }
                        continue;
                    }
                }
                if (!visited[nx][ny][nt % 3]) {
                    visited[nx][ny][nt % 3] = true;
                    q.offer(new Node(nx, ny, nt));
                }
                    
            }
        }

        return -1;
    }
	public static void main(String args[]) throws Exception
	{

		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
            N = sc.nextInt();
            map = new int[N][N];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            int startX = sc.nextInt();
            int startY = sc.nextInt();
            int endX = sc.nextInt();
            int endY = sc.nextInt();
            int result = bfs(startX, startY, endX, endY);
            System.out.println("#" + test_case + " " + result);
		}
	}
}