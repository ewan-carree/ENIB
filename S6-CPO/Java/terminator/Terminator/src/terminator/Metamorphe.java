package terminator;

public abstract class Metamorphe extends Terminator {
	private String appearance = "personne";
	
	public Metamorphe(String appearance) {
		this.appearance = appearance;
	}
	
	public Metamorphe(int serial_number, String appearance) {
		super(serial_number);
		this.appearance = appearance;
	}
	
	@Override
	public void sePresente(){
		System.out.println("Je suis sous l'apparence de ...");
	}

	public void setAppearance(String appearance) {
		this.appearance = appearance;
	}
	
}
