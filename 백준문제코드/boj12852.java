import java.util.Scanner;

public class boj12852 {

    public static int less(int a, int b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    public static void main(String[] args) {
        int N, i, j, x, min;

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        int home[][] = new int[N + 1][3];
        int dp[][] = new int[N + 1][3];

        for (i = 1; i <= N; i++) {
            for (j = 0; j < 3; j++) {
                home[i][j] = sc.nextInt();
                if (i == 1) {
                    dp[i][j] = home[i][j];
                }
            }
        }

        min = 1000001;

        for (x = 0; x < 3; x++) {// 1번집이 각각 R,G,B로 칠할때(=N번집이 각각 R,G,B가 아닐때)
            if (x == 0) {
                dp[2][0] = 1000001;
                dp[2][1] = home[2][1] + home[1][0];
                dp[2][2] = home[2][2] + home[1][0];

                for (i = 3; i <= N; i++) {
                    dp[i][0] = home[i][0] + less(dp[i - 1][1], dp[i - 1][2]);
                    dp[i][1] = home[i][1] + less(dp[i - 1][0], dp[i - 1][2]);
                    dp[i][2] = home[i][2] + less(dp[i - 1][0], dp[i - 1][1]);
                }
                min = less(min, less(dp[N][1], dp[N][2]));
            }
            else if (x == 1) {
                dp[2][1] = 1000001;
                dp[2][0] = home[2][0] + home[1][1];
                dp[2][2] = home[2][2] + home[1][1];

                for (i = 3; i <= N; i++) {
                    dp[i][0] = home[i][0] + less(dp[i - 1][1], dp[i - 1][2]);
                    dp[i][1] = home[i][1] + less(dp[i - 1][0], dp[i - 1][2]);
                    dp[i][2] = home[i][2] + less(dp[i - 1][0], dp[i - 1][1]);
                }
                min = less(min, less(dp[N][0], dp[N][2]));
            }
            else if (x == 2) {
                dp[2][2] = 1000001;
                dp[2][0] = home[2][0] + home[1][2];
                dp[2][1] = home[2][1] + home[1][2];

                for (i = 3; i <= N; i++) {
                    dp[i][0] = home[i][0] + less(dp[i - 1][1], dp[i - 1][2]);
                    dp[i][1] = home[i][1] + less(dp[i - 1][0], dp[i - 1][2]);
                    dp[i][2] = home[i][2] + less(dp[i - 1][0], dp[i - 1][1]);
                }
                min = less(min, less(dp[N][0], dp[N][1]));
            }
        }

        System.out.println(min);
    }
}
