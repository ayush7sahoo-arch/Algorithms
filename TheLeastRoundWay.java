//java is the best
import java.util.Scanner;

public class TheLeastRoundWay {

    static class Node{
        pair p;
        char c;

        Node(pair p,char c){
            this.p=p;
            this.c=c;
        }

        public Node() {
        }
        

    }

    static long min(long a,long b){
        return (a<b?a:b);
    }

    static long power(pair p){
        return min(p.a,p.b);
    }

    static class pair{
        long a;
        long b;

        public pair() {
        }

        pair(long a,long b){
            this.a=a;
            this.b=b;
        }
        pair add(pair other){
            return new pair(this.a+other.a, this.b+other.b);
        }
    } 

    public static pair extractPower(long n){
        if(n==1)return new pair(0,0);
        long t=n;
        long c2=0,c5=0;
        while(t%2==0){
            c2++;
            t/=2;
        }
        t=n;
        while(t%5==0){
            c5++;
            t/=5;
        }
        return new pair(c2, c5);
    }

    static Scanner sc=new Scanner(System.in);


    public static void solve(){
        int n=sc.nextInt();
        int [][]a=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=sc.nextInt();
            }
        }

        Node[][]dp=new Node[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=new Node();
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pair currentPower = extractPower(a[i][j]);
                if(i==0&&j==0){
                    dp[i][j].p=currentPower;
                    dp[i][j].c='S';
                }else if(i==0){
                    dp[i][j].p=dp[i][j - 1].p.add(currentPower);
                    dp[i][j].c='R';
                }else if(j==0){
                    dp[i][j].p=dp[i - 1][j].p.add(currentPower);
                    dp[i][j].c='D';
                }else{
                    //fuck the node
                    pair u=dp[i-1][j].p.add(currentPower);
                    pair l=dp[i][j-1].p.add(currentPower);

                    if(u.b<l.b){
                        dp[i][j].p=u;
                        dp[i][j].c='D';
                    }else{
                        dp[i][j].p=l;
                        dp[i][j].c='R';
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         System.out.print(dp[i][j].c+" ");
        //     }
        //     System.out.println();
        // }

        //print the fuckin zeros
        System.out.println(power(dp[n-1][n-1].p));
        // String path="";
        StringBuilder pathBuilder = new StringBuilder();

        //back track
        int i=n-1,j=n-1;
        while(i!=0 || j!=0){
            if(dp[i][j].c=='R'){
                pathBuilder.append('R');
                j--;
            }else{
                pathBuilder.append('D');
                i--;
            }
        }
        System.out.println(pathBuilder.reverse());

    }

    public static void main(String[] args) {
        solve();
    }
}
