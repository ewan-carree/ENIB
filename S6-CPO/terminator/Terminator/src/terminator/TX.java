package terminator;

public class TX extends Metamorphe {
	private int serial_number;
	private String appearance;
	
	public TX(int serial_number, String appearance) {
		super(serial_number, appearance);
	}
	
	public void reprogramme(T800 terminator) {
		terminator.setAmical(false);
	}

}
