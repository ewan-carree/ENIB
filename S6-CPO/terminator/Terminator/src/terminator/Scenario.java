package terminator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

/**
 * @author carree
 *
 */

public class Scenario {
	
	private static final int MAX_SIZE = 5;
	private static final Random RANDOM = new Random();
	
	private static final List<Priority> VALUES = Collections.unmodifiableList(Arrays.asList(Priority.values()));
	public static Priority randomPriority()  {
		return VALUES.get(RANDOM.nextInt(VALUES.size()));
	}
	
	public static Human getRandom(List<Human> array) {
	    int rnd = new Random().nextInt(array.size());
	    return array.get(rnd);
	}

	public static void main(String[] args) {
		//System.out.println("Dialogue entre machines.");
		
		//liste de nom pour créer humains
		List<String> name_list = new ArrayList<>(MAX_SIZE); //diamond operator
		name_list.add("Jean"); 
		name_list.add("Paul"); 
		name_list.add("Lou"); 
		name_list.add("Anne"); 
		name_list.add("Ewan");
		
		//liste d'humains
		List<Human> human_list = new ArrayList<>(MAX_SIZE);
		for (String name : name_list) {
			Human human = new Human(name, 30, false, 50, 0123, randomPriority());
			human_list.add(human);
		}
		
		//liste de robots
		List<T800> robot_list = new ArrayList<>(MAX_SIZE);
		for (int i = 0; i < MAX_SIZE; i++) {
			T800 robot = new T800(i, human_list.get(i)); //serial_number + owner
			robot_list.add(robot);
		}
		
		//ajout cible
		for (T800 robot : robot_list) {
			robot.addTarget(getRandom(human_list));
			robot.addTarget(getRandom(human_list));
		}
		
		//Affichage avec surcharge str
		for (T800 robot : robot_list) {
			System.out.println(robot);
		}
		
		
	}

}
