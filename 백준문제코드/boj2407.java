import java.math.BigInteger;
import java.util.Scanner;

public class boj2407 {
    public static void main(String[] args){
        int n,m,i;
        Scanner sc = new Scanner(System.in);

        n=sc.nextInt();
        m=sc.nextInt();

        BigInteger result = new BigInteger(Integer.toString(n));

        for(i=1;i<m;i++){
            BigInteger val1 = new BigInteger(Integer.toString(n-i));
            result=result.multiply(val1);
        }

        for(i=m;i>=1;i--){
            BigInteger val2 = new BigInteger(Integer.toString(i));
            result=result.divide(val2);
        }
        System.out.println(result);
    }
}
