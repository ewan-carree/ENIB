package hulk;

public interface Hulk extends Action {
	@Override
	public default void swallowSubstance(BruceDanner b) {
		// TODO Auto-generated method stub
		b.setState(State.NOT_CONTAMINED);
	}

	@Override
	public default void meetBetty(BruceDanner b) {
		// TODO Auto-generated method stub
		present(b);
		b.setState(State.CONTAMINED);
	}

	@Override
	public default void present(BruceDanner b) {
		// TODO Auto-generated method stub
		System.out.println("Grrrr");
		
	}
}
