package hulk;

public class Contamined implements StateBruceDanner {

	@Override
	public void present() {
		System.out.println("I'd have to kill you");
	}

	@Override
	public StateBruceDanner swallowSubstance() {
		// TODO Auto-generated method stub
		return this;
	}

	@Override
	public StateBruceDanner meetBetty() {
		// TODO Auto-generated method stub
		return HULK;
	}
	
}
