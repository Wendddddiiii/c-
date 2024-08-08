#include "./rethrow.h"

#include <exception>
#include <iostream>
#include <utility>
#include <vector>

const std::set<std::string> db_conn::blacklist_ = {"hsmith"};

auto db_conn::try_connect(const std::string &uname, const std::string &pword) -> void {
    if (!active_) {
        n_attempts_ += 1;
        if (blacklist_.contains(uname)) {
            throw std::domain_error(uname + " is not allowed to login.");
        } else if (n_attempts_ % 2 == 0) {
            throw std::runtime_error("HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0");
        }

        active_ = pword.length() >= 8;
    }
}

auto db_conn::is_active() const-> bool {
    return active_;
}

auto make_connection(db_conn &db, const std::string &uname, const std::string &pword) -> void {
    try {
        db.try_connect(uname, pword);
    } catch(const std::domain_error &e) {
        throw std::string{e.what()};
    } catch(const std::runtime_error &e) {
        throw std::string{e.what()};
    }
}

int main() {
    auto db = db_conn{};
    const auto attempts = std::vector<std::pair<std::string, std::string>> {
        {"hsmith", "swagger/10"},
        {"vegeta", "over9000"},
        {"billgates", "apple<3"},
        {"billgates", "macros0ft"},
        {"billgates", "m1cros0ft"},
    };
    for (const auto &[uname, pwd] : attempts) {
        try {
        make_connection(db, uname, pwd);
        } catch (const std::string &e) {
            std::cout << "Could not establish connection: " << e << std::endl;
        }
    }
}

/**
 * Output:
 * Could not establish connection: hsmith is not allowed to login.
 * Could not establish connection: HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0
 * Could not establish connection: HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0
 */
