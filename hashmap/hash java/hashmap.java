import java.util.HashMap;
public class hashmap {
    public static void main(String[] args){
        HashMap<Integer,String> hashMap = new HashMap<>();//注意 左边是key右边是value
        hashMap.put(1,"first");  //存入key和value
        hashMap.put(2, "second");
        hashMap.put(3, "three");
        hashMap.put(4, "four");
        System.out.println(Getexplain(hashMap,1));
        System.out.println(hashMap.size());//   计算长度
        hashMap.remove(3); //      删除键对 
        System.out.println(Getexplain(hashMap, 3));
    }
   static String Getexplain(HashMap <Integer, String> a,Integer b){
        return a.get(b);
    }
}
