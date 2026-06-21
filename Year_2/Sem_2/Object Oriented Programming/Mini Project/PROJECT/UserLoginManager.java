package PROJECT;

import java.io.*;
import java.util.*;

public class UserLoginManager {
    private static final String FILE_NAME = "users.txt";

    // Load users from file into a Map
    public static Map<String, String[]> loadUsers() {
        Map<String, String[]> users = new HashMap<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 3) {
                    users.put(parts[0], new String[]{parts[1], parts[2]}); // username -> [password, role]
                }
            }
        } catch (FileNotFoundException e) {
            // File may not exist initially
        } catch (IOException e) {
            System.out.println("Error reading user file: " + e.getMessage());
        }
        return users;
    }

    // Save a new user to the file
    public static boolean registerUser(String username, String password, String role) {
        Map<String, String[]> users = loadUsers();
        if (users.containsKey(username)) return false;

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true))) {
            writer.write(username + "," + password + "," + role);
            writer.newLine();
            return true;
        } catch (IOException e) {
            System.out.println("Error writing to user file: " + e.getMessage());
            return false;
        }
    }
}
