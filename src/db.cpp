
// db.cpp
#include "db.h"

Database* Database::instance = nullptr;

// Constructor
Database::Database(const std::string& name, const std::string& username, const std::string& password){
    db = name;
    Database::username = username;
    Database::password = password;
    last_activity = std::time(nullptr); // Initialize the last activity timestamp
}

// Destructor
Database::~Database() {
    if (connected) {
        disconnect();
    }
}

// GetInstance
Database* Database::getInstance(const std::string& name, const std::string& username, const std::string& password) {
    if (instance == nullptr) {
        instance = new Database(name, username, password);
    } 
    else {
        if (instance->db == name && instance->username == username && instance->password == password) {
            return instance;
        } 
        else {
            throw std::runtime_error("invalid database name, username or password");
        }
    }
    return instance;
}

// Connect
void Database::connect() {
    connected = true;
}

// Disconnect
void Database::disconnect() {
    connected = false;
}

// isConnected
bool Database::isConnected() {
    return connected;
}

// Overloaded new
void* Database::operator new(size_t size) {
    void* p = malloc(size);
    if (p == nullptr) {
        throw std::bad_alloc();
    }
    std::cout << "overloaded new ";
    return p;
}

// Overloaded delete
void Database::operator delete(void* p) {
    free(p);
    std::cout << "overloaded delete ";
}

// Set and get username
void Database::set_username(const std::string& username) {
    this->username = username;
}
std::string Database::get_username() const{
    return username;
}

// Set and get password
void Database::set_password(const std::string& password) {
    this->password = password;
}
std::string Database::get_password() const{
    return password;
}

void Database::resetInstance() {
    if (instance != nullptr) {
      delete instance;
      instance = nullptr;
    }
  }

  // Copy constructor
Database::Database(const Database& db) {
    throw std::runtime_error("Copy operations are not allowed");
}

// Copy Assignment operator
Database& Database::operator=(const Database &db) {
    throw std::runtime_error("Assignment operations are not allowed");
}

// Move constructor
Database::Database(Database&& db) noexcept {
    throw std::runtime_error("Move operations are not allowed");
}

// Move Assignment Operator
Database& Database::operator=(Database&& db) noexcept {
    throw std::runtime_error("Move operations are not allowed");
}

// Check if the connection has timed out
bool Database::isTimeout() {
    if ((std::time(nullptr) - last_activity) > TIMEOUT) {
        connected = false;
        return true;
    }
    return false;
}

// Refresh connection to update the last activity timestamp
void Database::refreshConnection() {
    last_activity = std::time(nullptr);
}
