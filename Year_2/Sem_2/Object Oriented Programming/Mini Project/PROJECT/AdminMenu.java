package PROJECT;

import javax.swing.*;
import java.util.ArrayList;

public class AdminMenu {

    private Menu menu;
    private ArrayList<Order> orders = new ArrayList<>();

    public AdminMenu() {
        menu = new Menu();
        menu.loadFromFile("menu.txt");
        showAdminMenu();
    }

    private void showAdminMenu() {
        while (true) {
            String[] options = {
                "1. View Menu", 
                "2. Add Dish", 
                "3. Edit Dish",
                "4. Delete Dish",
                "5. Save Menu", 
                "6. View Sales Report",
                "7. Exit"
            };

            String choice = (String) JOptionPane.showInputDialog(
                null,
                "Select an option:",
                "Admin Panel",
                JOptionPane.PLAIN_MESSAGE,
                null,
                options,
                options[0]
            );

            if (choice == null || choice.startsWith("8")) break;

            switch (choice.charAt(0)) {
                case '1': viewMenu(); break;
                case '2': addDish(); break;
                case '3': editDish(); break;
                case '4': deleteDish(); break;
                case '5': saveMenu(); break;
                case '6': openSalesReport(); break;     
            }
        }
    }

    private void viewMenu() {
        StringBuilder sb = new StringBuilder("Dish List:\n");
        for (NoodleDish dish : menu.getDishes()) {
            sb.append(dish.toString()).append("\n");
        }
        JOptionPane.showMessageDialog(null, sb.toString());
    }

    private void addDish() {
        String name = JOptionPane.showInputDialog("Enter dish name:");
        if (name == null || name.trim().isEmpty()) return;

        String priceStr = JOptionPane.showInputDialog("Enter price:");
        double price;
        try {
            price = Double.parseDouble(priceStr);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Invalid price.");
            return;
        }

        String[] statusOptions = {"AVAILABLE", "UNAVAILABLE"};
        String status = (String) JOptionPane.showInputDialog(null, "Select status:", "Dish Status",
                JOptionPane.QUESTION_MESSAGE, null, statusOptions, statusOptions[0]);

        if (status == null) return;

        NoodleDish dish = new NoodleDish(name, price, NoodleDish.DishStatus.valueOf(status));
        menu.addDish(dish);
    }

    private void editDish() {
        String targetName = JOptionPane.showInputDialog("Enter the name of the dish to edit:");
        if (targetName == null || targetName.trim().isEmpty()) return;

        for (NoodleDish d : menu.getDishes()) {
            if (d.getName().equalsIgnoreCase(targetName)) {
                String newName = JOptionPane.showInputDialog("Enter new name:", d.getName());
                String newPriceStr = JOptionPane.showInputDialog("Enter new price:", d.getPrice());
                double newPrice;
                try {
                    newPrice = Double.parseDouble(newPriceStr);
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(null, "Invalid price.");
                    return;
                }
                String[] statusOptions = {"AVAILABLE", "UNAVAILABLE"};
                String newStatus = (String) JOptionPane.showInputDialog(null, "Select new status:", "Dish Status",
                        JOptionPane.QUESTION_MESSAGE, null, statusOptions, d.getStatus().toString());

                if (newStatus != null) {
                    NoodleDish updatedDish = new NoodleDish(newName, newPrice, NoodleDish.DishStatus.valueOf(newStatus));
                    menu.updateDish(d, updatedDish);
                    JOptionPane.showMessageDialog(null, "Dish updated.");
                }
                return;
            }
        }

        JOptionPane.showMessageDialog(null, "Dish not found.");
    }

    private void deleteDish() {
        String targetName = JOptionPane.showInputDialog("Enter the name of the dish to delete:");
        if (targetName == null || targetName.trim().isEmpty()) return;

        for (NoodleDish dish : menu.getDishes()) {
            if (dish.getName().equalsIgnoreCase(targetName)) {
                menu.removeDish(dish);
                JOptionPane.showMessageDialog(null, "Dish deleted.");
                return;
            }
        }
        JOptionPane.showMessageDialog(null, "Dish not found.");
    }

    private void saveMenu() {
        menu.saveToFile("menu.txt");
        JOptionPane.showMessageDialog(null, "Menu saved successfully.");
    }

    private void openSalesReport() {
    // Sample orders to simulate
    NoodleDish d1 = new NoodleDish("Mee Goreng", 8.0, NoodleDish.DishStatus.AVAILABLE);
    NoodleDish d2 = new NoodleDish("Kuey Teow", 9.5, NoodleDish.DishStatus.AVAILABLE);
    
    Order o1 = new Order("ORD001");
    o1.addOrderItem(new OrderItem(d1, 2));
    o1.addOrderItem(new OrderItem(d2, 1));

    Order o2 = new Order("ORD002");
    o2.addOrderItem(new OrderItem(d2, 3));

    orders.clear();
    orders.add(o1);
    orders.add(o2);

    new SalesReport(orders); // Show the report
    
}


}   



