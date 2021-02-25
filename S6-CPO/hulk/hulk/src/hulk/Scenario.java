package hulk;

public class Scenario {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BruceDanner bd = new BruceDanner(StateBruceDanner.NON_CONTAMINED);
		
		bd.present();
		bd.meetBetty();
		bd.present();
		bd.swallowSubstance();
		bd.present();
		bd.swallowSubstance();
		bd.present();
		bd.meetBetty();
		bd.present();
		bd.meetBetty();
		bd.present();
		bd.meetBetty();
		bd.present();
		bd.swallowSubstance();
		bd.present();
	}

}
