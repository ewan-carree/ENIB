package terminator;

import java.util.LinkedList;

public class T800 extends Terminator {
	
	private boolean friendly = true;
	private int serial_number;
	private LinkedList<Human> target; //meilleur en set pour éviter les doublons
	private final Human owner;
	
	public T800(int serial_number, Human owner) {
		super(serial_number);
		this.owner = owner;
		this.target = new LinkedList<Human>();
	}
	
	public void setAmical(boolean state) {
		this.friendly = state;
	}
	
	@Override
	public void termine() {
		if (friendly) {
			System.out.println("Hasta la vista, Baby ...");
		} else {
			super.termine();
		}
	}

	public LinkedList<Human> getTarget() {
		LinkedList<Human> target = sort();
		return target;
	}

	private LinkedList<Human> sort() {
		this.target.sort(new PrioritySorter());
		return this.target;
	}

	//ajout cible
	public void addTarget(Human target) {
		this.target.add(target);
	}
	
	//liste d'humains attaqués
	public LinkedList<Human> attack() {
		if (friendly) { // si gentil
			return getTarget();
		} else { //si méchant
			this.owner.setPriority(Priority.EXTRA_HIGH); // owner devient cible principale
			addTarget(this.owner);
			return getTarget();
		}
	}
	
	//surcharge print
	@Override
	public String toString() {
		LinkedList<Human> targets = attack();
		String result = "I'm owned by " + this.owner.getName() + " and I'm attacking : ";
		for (Human target : targets) {
			result += target.getName() + "-" + target.getPriority() + ", " ;
		}
		return result.substring(0, result.length() - 2);
	}
	

}
