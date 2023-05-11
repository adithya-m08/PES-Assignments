import java.util.*;
import java.io.*;

class ArrayList2 {
  public static void main(String[] args) {
    ArrayList<String> animals = new ArrayList<>();

    // add elements in the array list
    animals.add("Dog");
    animals.add("Cat");
    animals.add("Horse");
    System.out.println("ArrayList: " + animals);

	// get the element from the arraylist
	String str = animals.get(1);
    System.out.print("Element at index 1: " + str);

		//change
		animals.set(2,"Goat");
		System.out.println("ArrayList: " + animals);
    // remove element from index 2
     str = animals.remove(2);

    System.out.println("Updated ArrayList: " + animals);
    System.out.println("Removed Element: " + str);

	//Sort
		Collections.sort(animals);
        System.out.println("after sorting animals:");
        System.out.println(animals);
  }
}
