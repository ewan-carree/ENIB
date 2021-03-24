package paintItBlack;

import javax.swing.JLabel;

@SuppressWarnings("serial")
public class NombreBattements extends JLabel implements Observateur {
	private int nb_battements;
	
	public NombreBattements() {
		super("Nombre de battements : 0");
	}

	@Override
	public void notifie() {
		this.nb_battements ++;
		setText("Nombre de battements : " + String.valueOf(this.nb_battements));
	}
}
