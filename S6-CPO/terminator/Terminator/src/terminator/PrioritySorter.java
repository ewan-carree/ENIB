package terminator;

import java.util.Comparator;

public class PrioritySorter implements Comparator<Human> {
	
	@Override
    public int compare(Human p1, Human p2) {
        return p1.getPriority().compareTo(p2.getPriority());
    }
}
