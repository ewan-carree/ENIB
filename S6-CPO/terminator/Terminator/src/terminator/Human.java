package terminator;

public class Human {
	private String name;
	private int age;
	private boolean gender;
	private int id;
	private int social_security_id;
	private Priority priority;
	
	public Human(String name, int age, boolean gender, int id, int social_security_id, Priority priority) {
		this.name = name;
		this.age = age;
		this.gender = gender;
		this.id = id;
		this.social_security_id = social_security_id;
		this.setPriority(priority);
	}
	
//	@Override
//	public String toString() {
//		String result = "I'm " + this.name + "\nAnd I'm attacked by : ";
//		for 
//		return result;
//	}

	public Priority getPriority() {
		return this.priority;
	}

	public void setPriority(Priority priority) {
		this.priority = priority;
	}
	
	public String getName() {
		return name;
	}
}
