#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== UNO TURN ORDER SCENE == " << std::endl;
    std::unique_ptr<List<Player>> table1 = makeList<Player>();

    // Form initial table with players
    table1->addFront(new Player(1, "Alec"));
    table1->addFront(new Player(2, "Billy"));
    table1->addFront(new Player(3, "Carson"));
    table1->addFront(new Player(4, "Dylan"));
    std::cout << std::endl << "-- STARTING TURN ORDER --" << std::endl;
    table1->print();

    // New player joins mid-order
    table1->addAnywhere(2, new Player(5, "Ethan"));
    std::cout << std::endl << "-- TURN ORDER AFTER ETHAN JOINS MID-ORDER --" << std::endl;
    table1->print();

    // Someone plays a reverse card
    table1->reverse();
    std::cout << std::endl << "-- TURN ORDER AFTER REVERSE CARD --" << std::endl;
    table1->print();

    // Someone steps away from the table
    table1->deleteAnywhere(3);
    std::cout << std::endl << "-- TURN ORDER AFTER CARSON LEAVES TABLE --" << std::endl;
    table1->print();

    // Form 2nd table
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addFront(new Player(6, "Fernando"));
    table2->addFront(new Player(7, "Gilbert"));
    table2->addFront(new Player(8, "Hael"));

    // Print both tables
    std::cout << std::endl << "-- TABLE 1 --" << std::endl;
    table1->print();
    std::cout << std::endl << "-- TABLE 2 --" << std::endl;
    table2->print();

    // Concat and print new tables
    table1->concat(table2.get());
    std::cout << std::endl << "-- TABLE 1 AFTER MERGE --" << std::endl;
    table1->print();
    std::cout << std::endl << "-- TABLE 2 AFTER MERGE --" << std::endl;
    table2->print();

    return 0;
}