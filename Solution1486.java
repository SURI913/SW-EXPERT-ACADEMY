import java.util.Scanner;


public class Solution1486 {
    private static int N;
    private static int B;
    private static int[] heights = new int[21];
    private static int answer;

    private static void dfs(int idx, int sum) {
        if (sum >= B) {
            //선반 높이 이상이면 갱신
            answer = Math.min(answer, sum);
            return;
        }

        // 탐색 끝
        if (idx == N) {
            return;
        }

        //가지치기
        if (sum >= answer) {
            return;
        }
        //현재 직원 선택
        dfs(idx + 1, sum + heights[idx]);
        //직원선택 안함
        dfs(idx + 1, sum);
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
        for (int test_case = 1; test_case <= T; test_case++) {
            //입력
            N = sc.nextInt();
            B = sc.nextInt();
            for(int i = 0; i < N; i++) {
                heights[i] = sc.nextInt();
            }

            answer = Integer.MAX_VALUE;
            dfs(0, 0);
            System.out.println("#" + test_case + " " + (answer - B));
        }

        sc.close();
    }
}
