import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;


public class Main {
	
	static Node[] vertices;

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int nCases = Integer.parseInt(reader.readLine());
		
		while(nCases-- > 0){
			String[] parts = reader.readLine().split(" ");
			
			int A = Integer.parseInt(parts[0]);
			int B = Integer.parseInt(parts[1]);
			int C = Integer.parseInt(parts[2]);
			
			vertices = new Node[A];
			
			for(int i = 0; i < A; i++)
				vertices[i] = new Node();
			
			for(int i = 0; i < B; i++){
				parts = reader.readLine().split(" ");
				addEdge(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]));
			}
			
			int group = 0;
			HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
			
			for(int i = 0; i < A; i++){
				if(vertices[i].group == -1) {
					DFS(vertices[i], group);
					map.put(group++, 0);
				}
				map.put(vertices[i].group, map.get(vertices[i].group) + 1);
			}
			
			int sum = 0;
			
			ArrayList<Integer> vals = new ArrayList<Integer>(map.values());
			Collections.sort(vals);
			int idx = vals.size()-1;
			
			while(C-- > 0 && sum < A)
				sum += vals.get(idx--);
				
			System.out.println(sum);
		}
	}
	
	static void addEdge(int x, int y){
		vertices[x].next.add(vertices[y]);
		vertices[y].next.add(vertices[x]);
	}
	
	static void DFS(Node current, int group){
		if(current.group == group) return;
		current.group = group;
		
		for(Node next : current.next) DFS(next, group);
	}

}

class Node{
	int group = -1;
	ArrayList<Node> next = new ArrayList<Node>();
}