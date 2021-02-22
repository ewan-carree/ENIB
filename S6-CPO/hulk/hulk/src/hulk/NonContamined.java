package hulk;

public interface NonContamined extends Action {
	@Override
	public default void swallowSubstance(BruceDanner b) {
		// TODO Auto-generated method stub
		b.setState(State.CONTAMINED);
	}

	@Override
	public default void meetBetty(BruceDanner b) {
		// TODO Auto-generated method stub
		present(b);
	}

	@Override
	public default void present(BruceDanner b) {
		// TODO Auto-generated method stub
		System.out.println("I'm Bruce Danner");
	}
}
