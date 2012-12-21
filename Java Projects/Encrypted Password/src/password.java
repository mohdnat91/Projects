import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class password {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		
		int N = Integer.parseInt(reader.readLine());
		
		while(N-- > 0){
			String password = reader.readLine();
			String original = reader.readLine();
			
			byte[] y = original.getBytes();
			int lo = y.length;
			
			Arrays.sort(y);
			
			int diff = password.length() - original.length();
			int i = 0;
			
			for(; i <= diff; i++){
				int j = diff - i;
				String temp = password.substring(i, password.length()-j);
				byte[] x = temp.getBytes();
				Arrays.sort(x);
				
				int k = 0;
				for(; k < lo; k++)
					if(x[k] != y[k]) break;
				
				if(k == lo) break;
			}
			
			if(i > diff) System.out.println("NO");
			else System.out.println("YES");
		}

	}

}
