
import java.util.*;

public class Main {

    public static int n, result = 0;
    public static int[][] graph = new int[26][26];

    public static int[] houseam = new int[600];


    public  static boolean dfs(int x, int y){
        if ( x <= -1 || x >= n || y <= -1 || y >= n){
            return false;
        }
        // 노드 방문이 안되었을 경우
        if (graph[x][y] == 1){
            graph[x][y] = 0;
            houseam[result]++;
            // 상 하 좌 우 재귀 호출
            dfs(x-1,y);
            dfs(x, y-1);
            dfs(x+1, y);
            dfs(x, y+1);
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();

        // 2차원 리스트 맵 정보 입력
        for(int i = 0; i < n; i++){
            String str = sc.nextLine();
            for( int j = 0; j< n; j++){
                graph[i][j] = str.charAt(j) - '0'; // 값 저장
            }
        }

        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                // 현재 위치에서 DFS 수행
                if (dfs(i, j)){
                    result += 1;
                }
            }
        }
        System.out.println(result);
        int[] newArr = Arrays.copyOf(houseam, result);
        Arrays.sort(newArr);
        for(int i = 0; i< result; i++){
            System.out.println(newArr[i]);
        }
    }
}
