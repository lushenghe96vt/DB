#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"
#include "db.h"
#include <thread>

TEST_CASE("Database operations - Copy, Move, Timeout", "[Database]") {
    Database* db = Database::getInstance("test.db", "user", "pass");
    Database* db1 = Database::getInstance("test.db", "user", "pass");
    Database* db2 = Database::getInstance("test.db", "user", "pass");

    SECTION("Timeout functionality - Connection becomes inactive after timeout") {
        db->connect();
        REQUIRE(db->isConnected() == true);

        // Wait for more than 5 seconds to trigger timeout
        std::this_thread::sleep_for(std::chrono::seconds(6));
        REQUIRE(db->isTimeout() == true);
        REQUIRE(db->isConnected() == false);
    }

    SECTION("Refresh connection prevents timeout") {
        db->connect();
        REQUIRE(db->isConnected() == true);

        // Refresh connection before timeout
        std::this_thread::sleep_for(std::chrono::seconds(3));
        db->refreshConnection();
        REQUIRE(db->isTimeout() == false);

        // Sleep for 3 more seconds and check again
        std::this_thread::sleep_for(std::chrono::seconds(3));
        REQUIRE(db->isTimeout() == false);
    }
}