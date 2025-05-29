import java.util.Scanner;
class Pair{
    int x;
    int y;

    Pair(int x,int y){
        this.x=x;
        this.y=y;
    }
}

public class Close {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        
        for(int i=0;i<t;i++){
            int n=sc.nextInt();
            Pair[] points=new Pair[n];
            for(int j=0;j<n;j++){
                points[j].x=sc.nextInt();
                points[j].y=sc.nextInt();
            }
            int xmax=Integer.MIN_VALUE;
            int ymax=Integer.MIN_VALUE;
            int xmin=Integer.MAX_VALUE;
            int ymin=Integer.MAX_VALUE;

            for(int j=0;j<n;j++){
                Pair p=points[j];
                if(p.x<xmin){
                    xmin=p.x;
                }
                if(p.y<ymin){
                    ymin=p.y;
                }
                if(p.x>xmax){
                    xmax=p.x;
                }
                if(p.y>ymax){
                    ymax=p.y;
                }

            }

            
            
        }
    }
}
