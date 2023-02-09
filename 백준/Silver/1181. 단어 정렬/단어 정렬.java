
import java.util.*;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> list = new ArrayList<String>();
        sc.nextLine();

        for (int i = 0; i < n; i++){
            list.add(sc.nextLine());
        }

        Set<String> set = new HashSet<String>(list); // 중복 제거
        List<String> res =new ArrayList<String>(set);

        Collections.sort(res, new Comparator<String>(){
            public int compare(String fst, String scd){
                if(fst.length() > scd.length()) return 1;
                else if(fst.length() < scd.length()) return -1;
                else return fst.compareTo(scd);
            }
        });
        for(int i = 0; i < res.size(); i++){
            System.out.println(res.get(i));
        }
    }
}
