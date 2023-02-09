
import java.util.*;

public class Main {

    static int n,m;
    static int[][] graph;

    static boolean[] check;

    public static void dfs(int now){
        check[now] = true; // 현재 위치
        for(int i = 1; i <= n; i++){
            // 연결 체크 및 방문 노드 확인
            if (graph[now][i] == 1 && check[i] == false){
                dfs(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        graph = new int[n+1][n+1];

        for (int i =0; i < m; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        check = new boolean[n+1];
        int con = 0;
        for(int i = 1; i <= n; i++){
            if(check[i] == false){
                dfs(i);
                con++;
            }
        }
        System.out.println(con);
    }
}
