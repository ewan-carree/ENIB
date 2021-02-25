package hulk;

public interface StateBruceDanner {
	public static final StateBruceDanner HULK = new Hulk();
	public static final StateBruceDanner CONTAMINED = new Contamined();
	public static final StateBruceDanner NON_CONTAMINED = new NonContamined();
	public void present();
	public StateBruceDanner swallowSubstance();
	public StateBruceDanner meetBetty();
}
