import java.util.*;
//codeforces teri MKC

public class winner{
    static class Round{
        String name;
        int score;

        Round(String name,int s){
            this.name=name;
            this.score=s;
        }
    }

    public static void solve(){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        HashMap<String,Integer>score=new HashMap<>();
        List<Round>round=new ArrayList<>();
        // HashSet<String>blackList=new HashSet<>();
        int m=Integer.MIN_VALUE;String winner="";

        for(int i=0;i<n;i++){
            String name=sc.next();
            int s=sc.nextInt();
            round.add(new Round(name, s));
        }
        
        //find the total scores of all players
        for(Round r:round){
            if(score.containsKey(r.name)){
                score.put(r.name, r.score+score.get(r.name));
            }else{
                score.put(r.name,r.score);
            }
        }

        //find the max score
        for(int x:score.values()){
            if(x>m)m=x;
        }

        //identify the candidate who scored the first
        HashMap<String,Integer>fuck_u=new HashMap<>();
        for(Round r:round){
            if(fuck_u.containsKey(r.name)){
                fuck_u.put(r.name,r.score+fuck_u.get(r.name));
            }else{
                fuck_u.put(r.name,r.score);
            }

            if(fuck_u.get(r.name)>=m && score.get(r.name)==m){
                winner=r.name;
                break;
            }
        }
        System.out.println(winner);

    }
    public static void main(String[] args) {
        solve();
        
    }
}