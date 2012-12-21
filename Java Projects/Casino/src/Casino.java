import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Casino {	

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int nCases = Integer.parseInt(reader.readLine());
		int c = 1;
		
		while(nCases-- > 0){
			String line = reader.readLine().trim();
			
			int longest = 1;
			List<String> longestPal = new ArrayList<String>();
			
			for(int i = 0; i < line.length(); i++){
				for(int j = i+1; j < line.length(); j++){
					if(j-i+1 < longest) continue;
					if(isPalindrome(line.substring(i, j+1))){
						if(j-i+1 != longest){
							longest = j-i+1;
							longestPal = new ArrayList<String>();
						}
						longestPal.add(line.substring(i, j+1));
					}
				}
			}
			
			System.out.printf("Case #%d:\n", c++);
			
			for(int i = longestPal.size()-1; i >= 0; i--){
				String s = longestPal.get(i);
				System.out.println(s);
			}
		}
	}
	
	static boolean isPalindrome(String s){
		int head = 0;
		int tail = s.length()-1;
		while(head < tail){
			if(s.charAt(head) != s.charAt(tail)) return false;
			head++;
			tail--;
		}
		return true;
	}

}
