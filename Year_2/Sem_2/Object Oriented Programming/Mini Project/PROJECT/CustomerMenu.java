package PROJECT;

import javax.swing.*;
import java.util.*;

public class CustomerMenu {
    private Menu menu;
    private Order currentOrder;
    private static int orderCounter = 1001;

    public CustomerMenu() {
        menu = new Menu();
        menu.loadFromFile("menu.txt");
        currentOrder = new Order("ORD" + orderCounter++);
        showCustomerMenu();
    }

    private void showCustomerMenu() {
        while (true) {
            String[] options = {
                "1. View Menu",
                "2. Place Order",
                "3. View Current Order",
                "4. Submit Order",
                "5. Edit/Delete Items in Order",
                "6. Logout"
            };

            String choice = (String) JOptionPane.showInputDialog(
                null,
                "Select an option:",
                "Customer Panel",
                JOptionPane.PLAIN_MESSAGE,
                null,
                options,
                options[0]
            );

            if (choice == null || choice.startsWith("6")) break;

            switch (choice.charAt(0)) {
                case '1': viewMenu(); break;
                case '2': placeOrder(); break;
                case '3': viewCurrentOrder(); break;
                case '4': submitOrder(); break;
                case '5': editOrDeleteOrderItem(); break;
            }
        }
    }

    private void viewMenu() {
        StringBuilder sb = new StringBuilder("Available Dishes:\n");
        for (NoodleDish dish : menu.getDishes()) {
            if (dish.getStatus() == NoodleDish.DishStatus.AVAILABLE) {
                sb.append(dish.getName()).append(" - RM").append(dish.getPrice()).append("\n");
            }
        }
        JOptionPane.showMessageDialog(null, sb.toString());
    }

    private void placeOrder() {
        List<NoodleDish> availableDishes = new ArrayList<>();
        for (NoodleDish d : menu.getDishes()) {
            if (d.getStatus() == NoodleDish.DishStatus.AVAILABLE) {
                availableDishes.add(d);
            }
        }

        if (availableDishes.isEmpty()) {
            JOptionPane.showMessageDialog(null, "No available dishes.");
            return;
        }

        String[] dishNames = availableDishes.stream().map(NoodleDish::getName).toArray(String[]::new);
        String selected = (String) JOptionPane.showInputDialog(
            null, "Select dish to order:", "Menu",
            JOptionPane.QUESTION_MESSAGE, null, dishNames, dishNames[0]
        );

        if (selected == null) return;

        String qtyStr = JOptionPane.showInputDialog("Enter quantity:");
        int qty;
        try {
            qty = Integer.parseInt(qtyStr);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Invalid quantity.");
            return;
        }

        for (NoodleDish d : availableDishes) {
            if (d.getName().equals(selected)) {
                OrderItem item = new OrderItem(d, qty);
                currentOrder.addOrderItem(item);
                JOptionPane.showMessageDialog(null, "Added to order.");
                return;
            }
        }
    }

    private void viewCurrentOrder() {
        StringBuilder sb = new StringBuilder("Your Current Order:\n");
        for (OrderItem item : currentOrder.getItems()) {
            sb.append(item.getDish().getName())
              .append(" x ").append(item.getQuantity())
              .append(" = RM").append(item.getDish().getPrice() * item.getQuantity())
              .append("\n");
        }
        sb.append("Total: RM").append(currentOrder.getTotal());
        JOptionPane.showMessageDialog(null, sb.toString());
    }

    private void submitOrder() {
        if (currentOrder.getItems().isEmpty()) {
            JOptionPane.showMessageDialog(null, "Your order is empty!");
            return;
        }

        OrderStorage.addOrder(currentOrder);

        JOptionPane.showMessageDialog(null,
            "Order submitted successfully!\nOrder ID: " + currentOrder.getOrderID() +
            "\nTotal: RM" + currentOrder.getTotal());

        currentOrder = new Order("ORD" + orderCounter++);
    }

    private void editOrDeleteOrderItem() {
        if (currentOrder.getItems().isEmpty()) {
            JOptionPane.showMessageDialog(null, "Your order is empty!");
            return;
        }

        String[] itemNames = currentOrder.getItems().stream()
            .map(item -> item.getDish().getName() + " x " + item.getQuantity())
            .toArray(String[]::new);

        String selected = (String) JOptionPane.showInputDialog(
            null, "Select item to modify or delete:", "Edit/Delete Item",
            JOptionPane.QUESTION_MESSAGE, null, itemNames, itemNames[0]
        );

        if (selected == null) return;

        OrderItem selectedItem = null;
        for (OrderItem item : currentOrder.getItems()) {
            if (selected.startsWith(item.getDish().getName())) {
                selectedItem = item;
                break;
            }
        }

        if (selectedItem == null) return;

        String[] actions = {"Edit Quantity", "Delete Item"};
        String action = (String) JOptionPane.showInputDialog(
            null, "What would you like to do?", "Edit or Delete",
            JOptionPane.PLAIN_MESSAGE, null, actions, actions[0]
        );

        if (action == null) return;

        if (action.equals("Edit Quantity")) {
            String qtyStr = JOptionPane.showInputDialog("Enter new quantity:");
            try {
                int newQty = Integer.parseInt(qtyStr);
                if (newQty > 0) {
                    selectedItem.setQuantity(newQty);
                    JOptionPane.showMessageDialog(null, "Quantity updated.");
                } else {
                    JOptionPane.showMessageDialog(null, "Quantity must be positive.");
                }
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "Invalid input.");
            }
        } else if (action.equals("Delete Item")) {
            currentOrder.getItems().remove(selectedItem);
            JOptionPane.showMessageDialog(null, "Item removed from order.");
        }
    }
}
