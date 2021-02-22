package hulk;

public class BruceDanner implements Contamined, NonContamined, Hulk {
	
	private State state;

	public BruceDanner(State state) {
		// TODO Auto-generated constructor stub
		this.state = state;
	}

	@Override
	public void swallowSubstance(BruceDanner b) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void meetBetty(BruceDanner b) {
		// TODO Auto-generated method stub

	}

	@Override
	public void present(BruceDanner b) {
		// TODO Auto-generated method stub

	}

	public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
	}

}
