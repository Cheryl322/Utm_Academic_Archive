package PROJECT;

import java.util.ArrayList;

public class OrderStorage {
    private static ArrayList<Order> allOrders = new ArrayList<>();

    public static void addOrder(Order order) {
        allOrders.add(order);
    }

    public static ArrayList<Order> getAllOrders() {
        return allOrders;
    }
}
