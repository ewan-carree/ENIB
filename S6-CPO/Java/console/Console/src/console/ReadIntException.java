package console;

@SuppressWarnings("serial")
public class ReadIntException extends Exception {
	public ReadIntException() {
		super();
		System.out.println("You didn't enter a correct int parameter");
	}
}
