package hulk;

public class NonContamined implements StateBruceDanner {

	@Override
	public void present() {
		System.out.println("I'm Bruce Danner");
	}

	@Override
	public StateBruceDanner swallowSubstance() {
		// TODO Auto-generated method stub
		return CONTAMINED;
	}

	@Override
	public StateBruceDanner meetBetty() {
		// TODO Auto-generated method stub
		return this;
	}
	
}
