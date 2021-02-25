package hulk;

public class Hulk implements StateBruceDanner {

	@Override
	public void present() {
		System.out.println("Grrr");
	}

	@Override
	public StateBruceDanner swallowSubstance() {
		// TODO Auto-generated method stub
		return NON_CONTAMINED;
	}

	@Override
	public StateBruceDanner meetBetty() {
		// TODO Auto-generated method stub
		return CONTAMINED;
	}
}
