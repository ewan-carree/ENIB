package terminator;

public abstract class Terminator {
	private int serial_number;
	
	public Terminator(int serial_number) {
		this.serial_number = serial_number;
	}
	
	public Terminator() {
	}
	
	public void sePresente() {
		System.out.println("Je suis un Terminator et mon num�ro de s�rie est ...");
	}
	
	public void termine() {
		System.out.println("Vous avez termin�!");
	}
}
