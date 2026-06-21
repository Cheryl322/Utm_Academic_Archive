// FoodOrderingSystem.java
import java.util.*;

class OnlineOrder implements Order {
    private static final double SERVICE_CHARGE = 1.00;

    @Override
    public void orderFood(Food food) {
        food.prepare();
        double cost = food.getPrice() + SERVICE_CHARGE;
        Customer.grandTotal += cost;
        System.out.println(food.getName()+ " ordered online.");
        System.out.printf("Total = RM%.2f\n",cost);
        System.out.println();
    }
}

class OfflineOrder implements Order {
    private static final double SERVICE_CHARGE = 2.00;

    @Override
    public void orderFood(Food food) {
        food.prepare();
        double cost = food.getPrice() + SERVICE_CHARGE;
        Customer.grandTotal += cost;
        System.out.println(food.getName()+ " ordered offline.");
        System.out.printf("Total = RM%.2f\n",cost);
        System.out.println();
    }
}

abstract class Food {
    private String name;
    private double price;

    public Food(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() { return name; }
    public double getPrice() { return price; }
    public abstract void prepare();
}

class Pizza extends Food {
    public Pizza() {
        super("Hawaiian Chicken", 40.90);
    }

    @Override
    public void prepare() {
        System.out.println("Preparing Hawaiian Chicken Pizza...");
    }
}

class Burger extends Food {
    public Burger() {
        super("Double Cheeseburger", 18.35);
    }

    @Override
    public void prepare() {
        System.out.println("Preparing Double Cheeseburger...");
    }
}

class Customer {
    private String name;
    private Order orderType;
    public static double grandTotal = 0.0;

    public Customer(String name, Order orderType) {
        this.name = name;
        this.orderType = orderType;
    }

    public void placeOrder(Food food) {
        orderType.orderFood(food);
    }
}

interface Order {
    void orderFood(Food food);
}

class FoodOrderingSystem {
 //Method to add a customer to the system
    public static void addCustomer(Vector<Customer> cList, Customer c) {
    cList.add(c);
 }
 // Method to take orders from all customers in the system
 public static void takeOrders(Vector<Customer> cList) {
    for (Customer c: cList) {
        c.placeOrder(new Pizza());
        c.placeOrder(new Burger());
    }
 }
public static void main(String[] args) {
// Create a new customer list
    Vector<Customer> cList = new Vector<>();
//Add customers to the system
    addCustomer(cList, new Customer("Haris", new OnlineOrder()));
    addCustomer(cList, new Customer("Aliya", new OfflineOrder()));
//Take orders from all customers
    takeOrders(cList);
    System.out.printf("Grand Total Sales = RM%.2f\n",
    Customer.grandTotal);
}
}
