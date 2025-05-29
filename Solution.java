import java.util.Scanner;

public class Solution {

    public static String solve(int n,int k,String s) {
        Scanner scanner = new Scanner(System.in);

        int count0=0;
        for (char c:s.toCharArray()) {
            if (c=='0') {
                count0++;
            }
        }
        int count1= n-count0; 

        int nPairs=n/2;

        int np1=nPairs-k;

        if (count0< np1 || count1<np1) {
            return "NO";
        }

        int r0=count0-np1;
        int r1 = count1-np1;

        if (r0%2!=0||r1%2!=0) {
            return "NO";
        }

        int p=(r0/2)+(r1/2);

        if (p==k) {
            return "YES";
        } else {
            return "NO";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        String sol[]=new String[t];
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
        int k = scanner.nextInt();
        String s = scanner.next();
        sol[i]=solve(n, k, s);
        }

        for(int i=0;i<t;i++){
            System.out.println(sol[i]);
        }
        scanner.close();
    }
}