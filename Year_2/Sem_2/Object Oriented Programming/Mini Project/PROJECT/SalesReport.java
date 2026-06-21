package PROJECT;

import javax.swing.*;
import java.io.*;
import java.util.ArrayList;

public class SalesReport {
    private ArrayList<Order> orders;

    public SalesReport(ArrayList<Order> orders) {
        this.orders = orders;
        showMenu();
    }

    private void showMenu() {
        while (true) {
            String[] options = {
                "1. View Daily Report",
                "2. Export Daily Report to File",
                "3. Back"
            };

            String choice = (String) JOptionPane.showInputDialog(
                null,
                "Select an option:",
                "Sales Report Panel",
                JOptionPane.PLAIN_MESSAGE,
                null,
                options,
                options[0]
            );

            if (choice == null || choice.startsWith("3")) break;

            switch (choice.charAt(0)) {
                case '1': viewDailyReport(); break;
                case '2': exportReport(); break;
            }
        }
    }

    private void viewDailyReport() {
        StringBuilder sb = new StringBuilder("=== Daily Sales Report ===\n\n");
        double total = 0;

        for (Order order : orders) {
            sb.append("Order ID: ").append(order.getOrderID()).append("\n");
            for (OrderItem item : order.getItems()) {
                double subtotal = item.getDish().getPrice() * item.getQuantity();
                sb.append("- ").append(item.getDish().getName())
                  .append(" x ").append(item.getQuantity())
                  .append(" = RM").append(String.format("%.2f", subtotal)).append("\n");
                total += subtotal;
            }
            sb.append("\n");
        }

        sb.append("Total Sales: RM").append(String.format("%.2f", total));
        JOptionPane.showMessageDialog(null, sb.toString(), "Daily Report", JOptionPane.INFORMATION_MESSAGE);
    }

    private void exportReport() {
        String filename = JOptionPane.showInputDialog("Enter filename to export (e.g., report.txt):");
        if (filename == null || filename.trim().isEmpty()) return;

        exportDailyReportToFile(orders, filename.trim());
        JOptionPane.showMessageDialog(null, "Report exported to " + filename);
    }

    
    public static void exportDailyReportToFile(ArrayList<Order> orders, String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            double totalSales = 0;
            writer.write("=== Daily Sales Report ===\n\n");

            for (Order order : orders) {
                writer.write("Order ID: " + order.getOrderID() + "\n");
                for (OrderItem item : order.getItems()) {
                    double subtotal = item.getDish().getPrice() * item.getQuantity();
                    writer.write("- " + item.getDish().getName() + " x " + item.getQuantity() +
                            " = RM" + String.format("%.2f", subtotal) + "\n");
                    totalSales += subtotal;
                }
                writer.write("\n");
            }

            writer.write("Total Sales: RM" + String.format("%.2f", totalSales));
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Error exporting report: " + e.getMessage());
        }
    }
}
