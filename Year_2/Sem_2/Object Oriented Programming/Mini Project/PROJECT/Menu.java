package PROJECT;

import java.util.ArrayList;
import java.io.*;

public class Menu {
    private ArrayList<NoodleDish> dishes;

    public Menu() {
        dishes = new ArrayList<>();
    }
    public void addDish(NoodleDish dish) {
        dishes.add(dish);
        System.out.println("Added dish: " + dish.getName() + ", Price: " + dish.getPrice());
    }

    public void removeDish(NoodleDish dish) {
        dishes.removeIf(d -> d.getName().equalsIgnoreCase(dish.getName()));
        System.out.println("Removed dish: " + dish.getName());
    }


    public void listDishes() { 
        for (NoodleDish dish : dishes) {
            System.out.println("\n Dish: " + dish.getName() + ", Price: " + dish.getPrice());
        }
    }

    public void updateDish(NoodleDish oldDish, NoodleDish newDish) {
        int index = dishes.indexOf(oldDish);
        if (index != -1) {
            dishes.set(index, newDish);
            System.out.println("Updated dish from " + oldDish.getName() + " to " + newDish.getName());
        }
    }

    // 🔹 Save to file
    public void saveToFile(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (NoodleDish dish : dishes) {
                writer.write(dish.getName() + "," + dish.getPrice() + "," + dish.getStatus());
                writer.newLine();
            }
            System.out.println("Menu saved to file.");
        } catch (IOException e) {
            System.out.println("Error saving menu: " + e.getMessage());
        }
    }

    // 🔹 Load from file
    public void loadFromFile(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            dishes.clear();
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                String name = parts[0];
                double price = Double.parseDouble(parts[1]);
                NoodleDish.DishStatus status = NoodleDish.DishStatus.valueOf(parts[2]);
                dishes.add(new NoodleDish(name, price, status));
            }
            System.out.println("Menu loaded from file.");
        } catch (FileNotFoundException e) {
            System.out.println("Menu file not found. Starting with empty menu.");
        } catch (IOException  | IllegalArgumentException e) {
            System.out.println("Error loading menu: " + e.getMessage());
        }
    }

    public ArrayList<NoodleDish> getDishes() {
        return dishes;
    }
}
