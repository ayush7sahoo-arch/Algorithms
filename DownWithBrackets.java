import java.util.Scanner;

public class DownWithBrackets{
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int t=sc.nextInt();
        String ans[]=new String[t];
        for(int i=0;i<t;i++){
            String brs=sc.next();
            int l=0,r=0;
            for(int j=0;j<brs.length();j++){
                if(brs.charAt(j)=='('){
                    l++;
                }
                if(brs.charAt(j)==')'){
                    r++;
                }
                if(l==r && j+1<brs.length()){
                    ans[i]="YES";
                }
            }
            if(ans[i]!="YES"){
            ans[i]="NO";}
        }
        for(String i:ans){
            System.out.println(i);
        }
    }
}