package console;

@SuppressWarnings("serial")
public class ReadStringException extends Exception{
	public ReadStringException() {
		super();
		System.out.println("You didn't enter a correct String parameter");
	}
}
