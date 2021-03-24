package terminator;

public abstract class Terminator {
	private int serial_number;
	
	public Terminator(int serial_number) {
		this.serial_number = serial_number;
	}
	
	public Terminator() {
	}
	
	public void sePresente() {
		System.out.println("Je suis un Terminator et mon numéro de série est ...");
	}
	
	public void termine() {
		System.out.println("Vous avez terminé!");
	}
}
