package console;

import static org.junit.jupiter.api.Assertions.*;

import java.io.IOException;

import org.junit.jupiter.api.Test;

class ConsoleTest {

	@Test
	void readStringTest() throws IOException, ReadStringException {
		assertEquals("hello 2",Console.readString());
	}
	
	@Test
	void readIntTest() throws NumberFormatException, IOException, ReadIntException, ReadStringException {
		assertEquals(2, Console.readInt());
	}

}
