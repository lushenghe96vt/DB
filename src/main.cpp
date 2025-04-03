#include <iostream>
#include "db.h"

int main() {
    try {
        // Create a database instance
        Database* db = Database::getInstance("test.db", "user", "pass");
        db->connect();
        std::cout << "Database connected: " << db->isConnected() << std::endl;

        // Simulate some operations
        db->set_username("new_user");
        std::cout << "Username: " << db->get_username() << std::endl;

        // Check timeout functionality
        if (db->isTimeout()) {
            std::cout << "Connection timed out!" << std::endl;
        }

        db->disconnect();
        std::cout << "Database connected after disconnect: " << db->isConnected() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}