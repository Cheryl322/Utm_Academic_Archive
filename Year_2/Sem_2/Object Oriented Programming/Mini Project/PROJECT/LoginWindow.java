package PROJECT;

import javax.swing.*;

import java.util.Map;

public class LoginWindow {

    public LoginWindow() {
        showLoginMenu();
    }

    private void showLoginMenu() {
        String[] options = {"Login", "Register", "Exit"};
        while (true) {
            int choice = JOptionPane.showOptionDialog(null,
                    "Welcome to Noodle Management System",
                    "Login Menu",
                    JOptionPane.DEFAULT_OPTION,
                    JOptionPane.PLAIN_MESSAGE,
                    null,
                    options,
                    options[0]);

            if (choice == 0) {
                login();
            } else if (choice == 1) {
                register();
            } else {
                break;
            }
        }
    }

    private void login() {
        String username = JOptionPane.showInputDialog("Enter username:");
        if (username == null) return;

        String password = JOptionPane.showInputDialog("Enter password:");
        if (password == null) return;

        Map<String, String[]> users = UserLoginManager.loadUsers();
        if (users.containsKey(username)) {
            String[] details = users.get(username);
            if (details[0].equals(password)) {
                String role = details[1];
                JOptionPane.showMessageDialog(null, "Login successful as " + role + "!");
                if (role.equalsIgnoreCase("admin")) {
                    new AdminMenu();  // launch Admin UI
                } else {
                    new CustomerMenu();  // launch Customer UI
                }
            } else {
                JOptionPane.showMessageDialog(null, "Incorrect password.");
            }
        } else {
            JOptionPane.showMessageDialog(null, "User not found.");
        }
    }

    private void register() {
    String username = JOptionPane.showInputDialog("Choose a username:");
    if (username == null || username.trim().isEmpty()) return;

    String password = JOptionPane.showInputDialog("Choose a password:");
    if (password == null || password.trim().isEmpty()) return;

    String[] roles = {"admin", "customer"};
    String role = (String) JOptionPane.showInputDialog(
        null,
        "Select role:",
        "Choose Role",
        JOptionPane.QUESTION_MESSAGE,
        null,
        roles,
        roles[1]  // default is customer
    );
    if (role == null) return;

    boolean success = UserLoginManager.registerUser(username, password, role.toLowerCase());

    if (success) {
        JOptionPane.showMessageDialog(null, "Registration successful! You can now login.");
    } else {
        JOptionPane.showMessageDialog(null, "Username already exists.");
    }
}


    public static void main(String[] args) {
        new LoginWindow();
    }
}
