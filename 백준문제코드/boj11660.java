import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class boj11660 {
    public static void main(String[] args) throws IOException {
        int N, M, x, i, j, x1, y1, x2, y2;

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int tab[][] = new int[N][N];
        int dp[][] = new int[N][N];

        for (i = 0; i < N; i++) {
            StringTokenizer val = new StringTokenizer(bf.readLine());
            for (j = 0; j < N; j++) {
                tab[i][j] = Integer.parseInt(val.nextToken());
                if((i==0)&&(j==0)){
                    dp[i][j]=tab[i][j];
                }
                else if(i==0){
                    dp[i][j]=tab[i][j]+dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j]=tab[i][j]+dp[i-1][j];
                }
                else{
                    dp[i][j] = tab[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];                    
                }
            }
        }

        for (x = 0; x < M; x++) {
            StringTokenizer in = new StringTokenizer(bf.readLine());            
            x1 = Integer.parseInt(in.nextToken());
            y1 = Integer.parseInt(in.nextToken());
            x2 = Integer.parseInt(in.nextToken());
            y2 = Integer.parseInt(in.nextToken());
            if ((x1 == x2) && (y1 == y2)) {
                System.out.println(tab[x1 - 1][y1 - 1]);
            }
            else if ((x1 == 1) && (y1 == 1)) {
                System.out.println(dp[x2 - 1][y2 - 1]);
            }
            else if (x1 == 1) {
                System.out.println(dp[x2 - 1][y2 - 1] - dp[x2 - 1][y1 - 2]);
            }
            else if (y1 == 1) {
                System.out.println(dp[x2 - 1][y2 - 1] - dp[x1 - 2][y2 - 1]);
            }
            else {
                System.out.println(dp[x2 - 1][y2 - 1] - dp[x2 - 1][y1 - 2] - dp[x1 - 2][y2 - 1] + dp[x1 - 2][y1 - 2]);
            }
        }

        bf.close();
    }
  }
