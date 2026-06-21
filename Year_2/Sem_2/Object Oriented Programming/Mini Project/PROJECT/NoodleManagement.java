//package PROJECT;
import java.util.*;

public class NoodleManagement {
    public static void main(String[] args) {
        System.out.println("Noodle Management System Initialized.");

        try (Scanner scanner = new Scanner(System.in)) {
            Menu menu = new Menu();
            Admin admin = new Admin("admin", "1234");

            // Load existing menu
            menu.loadFromFile("menu.txt");

            // Simple login
            System.out.print("Enter username: ");
            String u = scanner.nextLine();
            System.out.print("Enter password: ");
            String p = scanner.nextLine();

        if (!admin.login(u, p)) {
            System.out.println("Invalid login.");
            return;
        }

        while (true) {
            System.out.println("\n1. Add Dish\n2. List Menu\n3. Save Menu\n4. Exit");
            System.out.print("Choose: ");
            int choice = scanner.nextInt(); scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Dish name: ");
                    String name = scanner.nextLine();
                    System.out.print("Price: ");
                    double price = scanner.nextDouble(); scanner.nextLine();
                    System.out.print("Status (AVAILABLE/UNAVAILABLE): ");
                    String statusInput = scanner.nextLine();
                    NoodleDish.DishStatus status = NoodleDish.DishStatus.valueOf(statusInput.toUpperCase());
                    NoodleDish dish = new NoodleDish(name, price, status);
                    admin.addDish(menu, dish);
                    break;
                case 2:
                    menu.listDishes();
                    break;
                case 3:
                    menu.saveToFile("menu.txt");
                    break;
                case 4:
                    System.out.println("Goodbye!");
                    return;
                default:
                    System.out.println("Invalid option.");
            }
        }
    }
    
}
}   

abstract class User {
    private String username;
    private String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }
	
    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public boolean login(String username, String password) {
        return this.username.equals(username) && this.password.equals(password);
    }   
}

class Admin extends User {
    public Admin(String username, String password) {
        super(username, password);
    }

    public void addDish(Menu menu, NoodleDish dish) {
        menu.addDish(dish);
    }
/* 
    public void removeDish(Menu menu, String dishName) {
        menu.removeDish(dishName);
    }

    public void updateDish(Menu menu, NoodleDish updatedDish) {
        menu.updateDish(updatedDish);
    }
*/
}

class Order{
    private String orderID;
    private ArrayList<OrderItem> OrderItems;

    public Order(String orderID) {
        this.orderID = orderID;
        this.OrderItems = new ArrayList<>();
    }

    public void addOrderItem(OrderItem item) {
        OrderItems.add(item);
        System.out.println("Added item: " + item.getDish().getName() + " to order " + orderID);
    }

    public double getTotal(){
        double total = 0;
        for (OrderItem item : OrderItems) {
            total += item.getDish().getPrice() * item.getQuantity();
        }
        return total;
    }

    public String getOrderID() {
        return orderID;
    }

    public ArrayList<OrderItem> getItems() {
        return OrderItems;
    }
}


class OrderItem{

    private NoodleDish dish;
    private int quantity;
    

    public OrderItem(NoodleDish dish, int quantity) {
        this.dish = dish;
        this.quantity = quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public NoodleDish getDish() {
        return dish;
    }

    public int getQuantity() {
        return quantity;
    }
}

