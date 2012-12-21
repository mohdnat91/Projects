import java.io.BufferedReader;
import java.io.InputStreamReader;


public class strings {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(reader.readLine());
		
		StringBuilder string;
		
		while(N-- > 0){
			string = new StringBuilder(reader.readLine());
			
			while(true){
				String op = reader.readLine();
				if(op.equals("END")) break;
				
				String[] parts = op.split(" ");
				
				if(parts[0].equals("I")){
					string.insert(Integer.parseInt(parts[2]), parts[1]);
				} else {
					int start = Integer.parseInt(parts[1]);
					int end = Integer.parseInt(parts[2]);
					System.out.println(string.substring(start, end-start+1));
				}
			}
		}

	}

}
