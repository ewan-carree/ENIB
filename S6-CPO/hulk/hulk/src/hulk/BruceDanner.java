package hulk;

public class BruceDanner {
	private StateBruceDanner state;
	
	public BruceDanner(StateBruceDanner state) {
		this.state = state;
	}

	public StateBruceDanner getState() {
		return state;
	}

	public void setState(StateBruceDanner state) {
		this.state = state;
	}

	public void present() {
		this.state.present();
	}

	public void swallowSubstance() {
		this.state = this.state.swallowSubstance();
	}

	public void meetBetty() {
		this.state = this.state.meetBetty();
	} 
	
	

}
