import java.util.Scanner;

public class BinaryString{
    public static String flip(String s,int idx){
        String n="";
        for(int i=0;i<=idx;i++){
            if(s.charAt(i)=='0'){
                n+='1';
            }else{
                n+='0';
            }
        }
        for(int i=idx+1;i<s.length();i++){
            n+=s.charAt(i);
        }
        return n;
    }

    public static int solve(String s,int n,int k){
        if(k==1){
            //count the number of zeros
            int zeros=0;
            for(int i=0;i<n;i++){
                if(s.charAt(i)=='0'){
                    zeros++;
                }
            }
            return zeros;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='0'){
                ans+=solve(flip(s, i),n, k-1);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int t;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        int ans[]=new int[t];
        for(int i=0;i<t;i++){
            int n=sc.nextInt();
            int k=sc.nextInt();
            String s=sc.next();
            ans[i]=solve(s, n, k);
        }
        for(int i=0;i<t;i++){
            System.out.println(ans[i]);
        }
        
    }
}