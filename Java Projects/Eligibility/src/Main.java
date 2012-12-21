import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int nCases = Integer.parseInt(reader.readLine());
		int c = 1;
		
		while(nCases-- > 0){
			int N = Integer.parseInt(reader.readLine());
			
			Map<String, Set<Integer>> contestants = new HashMap<String, Set<Integer>>();
			
			while(N-- > 0){
				String line = reader.readLine();
				
				int year = Integer.parseInt(line.substring(line.length()-5, line.length()).trim());
				String name = line.substring(0, line.length()-5);
				
				Set<Integer> temp = null;
				
				if(contestants.containsKey(name))
					temp = contestants.get(name);
				else {
					temp = new HashSet<Integer>();
					contestants.put(name, temp);
				}
				
				temp.add(year);
				
			}
			
			List<String> names = new ArrayList<String>();
			
			for(String n : contestants.keySet()){
				if(contestants.get(n).size() < 5) 
					names.add(n);
			}
			
			System.out.printf("Case #%d:\n", c++);
			
			Collections.sort(names);
			
			for(String h : names)
				System.out.println(h);
		}
	}

}
