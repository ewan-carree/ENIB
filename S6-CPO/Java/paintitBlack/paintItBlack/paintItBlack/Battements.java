package paintItBlack;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;


@SuppressWarnings("serial")
public class Battements extends JFrame {

	public static NombreBattements nb_battements = new NombreBattements();
	
	public Battements(String windowName) {
		super(windowName);
	}
	
	public void initializeBattements(){
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		setBackground(Color.red);
//		setSize(300,200); 
		
		JPanel newContentPane = new JPanel(new BorderLayout());
		newContentPane.add(nb_battements, BorderLayout.SOUTH);
		
		setContentPane(newContentPane);
		pack();
		setResizable(true);
		setVisible(true);
		
		int delay = 1000; //milliseconds
		ActionListener taskPerformer = new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				nb_battements.notifie();
			}
		};
		new Timer(delay, taskPerformer).start();
	}
}
