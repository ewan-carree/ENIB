package hulk;

public interface Contamined extends Action {
	
	
	@Override
	public default void swallowSubstance(BruceDanner b) {
		// TODO Auto-generated method stub
	}

	@Override
	public default void meetBetty(BruceDanner b) {
		// TODO Auto-generated method stub
		present(b);
		b.setState(State.HULK);
	}

	@Override
	public default void present(BruceDanner b) {
		// TODO Auto-generated method stub
		System.out.println("I can't tell you my name");
	}
}
