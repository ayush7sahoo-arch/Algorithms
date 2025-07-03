import java.util.Scanner;

public class theatreSquare{
    public static void solve(){
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long m=sc.nextLong();
        long a=sc.nextLong();

        long ans=((n-1)/a+1)*((m-1)/a+1);
        System.out.println(ans);
    }
    public static void main(String arg[]){
        solve();
    }
}