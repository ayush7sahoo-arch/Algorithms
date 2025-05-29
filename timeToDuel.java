import java.util.Scanner;

public class timeToDuel{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        String ans[]=new String[t];
        for(int i=0;i<t;i++){
            int n=sc.nextInt();
            int arr[]=new int[n];
            for(int j=0;j<n;j++){
                arr[j]=sc.nextInt();
            }
            boolean allOne=true;
            for(int j=0;j<n-1;j++){
                if(arr[j]==0 && arr[j+1]==0){
                    ans[i]="YES";
                }
                // if(arr[j]==1 && arr[j+1]==1 && j+2>=n && j-1<0){
                //     ans[i]="YES";
                // }
                if(arr[j]==0 || arr[j+1]==0){
                    allOne=false;
                }

            }
            if(allOne==true){
                ans[i]="YES";
            }
            
            if(ans[i]!="YES"){
                ans[i]="NO";
            }
        }
        for(int i=0;i<t;i++){
            System.out.println(ans[i]);
        }
    }
}