package console;
import java.io.*;


/**
* Console
* The Console program allow you to interact with the console.
* 
*
* @author  CARREE Ewan
* @version 1.0
* @since   2021-03-06
*/
public class Console {
	
	/**
	   * This method is used to print a string on the default output flow.
	   * @param myStr This is the string parameter of printString method.
	   */
	public static void printString(String myStr) {
		System.out.println(myStr);
	}
	
	/**
	   * This method is used to read a string from the default output flow.
	   * @exception IOException On input error.
	   * @return String
	   */
	public static String readString() throws IOException, ReadStringException {
		
		try {
			String myStr = null;
			BufferedReader inputStream = new BufferedReader(new InputStreamReader(System.in));
			myStr = inputStream.readLine();
			return myStr;
		} catch (IOException e) {
			throw new ReadStringException();
		} 
	}
	
	/**
	   * This method is used to add print an int on the default output flow.
	   * @param myInt This is the integer parameter of printInt method.
	   */
	public static void printInt(int myInt) {
		System.out.println(myInt);
	}
	
	/**
	   * This method is used to extract an int from a string written in the default output flow.
	   * @exception IOException On input error.
	   * @exception NumberFormatException On the format of number entered.
	   * @return int
	 * @throws ReadStringException 
	   */
	public static int readInt() throws IOException, NumberFormatException, ReadIntException, ReadStringException {
		try {
			int n = Integer.parseInt(readString());
			return n;
		} catch (IOException e) {
			throw new ReadIntException();
		} catch (NumberFormatException e) {
			throw new ReadIntException();
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException, ReadStringException {
		int n;
		try {
			n = readInt();
			printInt(n);
		} catch (ReadIntException e) {
			e.printStackTrace();
		}
		
	}
}
