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

    // Create players and give them some cards
    Player* alec = new Player(1, "Alec");
    alec->giveCard(new Card("Red", "4"));
    alec->giveCard(new Card("Blue", "3"));
    alec->giveCard(new Card("Yellow", "Reverse"));

    Player* billy = new Player(2, "Billy");
    billy->giveCard(new Card("Green", "6"));
    billy->giveCard(new Card("Green", "Skip"));
    billy->giveCard(new Card("Red", "7"));

    Player* carson = new Player(3, "Carson");
    carson->giveCard(new Card("Blue", "4"));
    carson->giveCard(new Card("Green", "2"));
    carson->giveCard(new Card("Red", "4"));

    Player* dylan = new Player(4, "Dylan");
    dylan->giveCard(new Card("Blue", "3"));
    dylan->giveCard(new Card("Green", "Reverse"));
    dylan->giveCard(new Card("Red", "7"));

    // Form initial table with players
    table1->addFront(alec);
    table1->addFront(billy);
    table1->addFront(carson);
    table1->addFront(dylan);
    std::cout << std::endl << "-- STARTING TURN ORDER --" << std::endl;
    table1->print();

    // Print hands of all players
    std::cout << std::endl << "-- STARTING HANDS --" << std::endl;
    std::cout << "Alec: ";
    alec->printHand();
    std::cout << "Billy: ";
    billy->printHand();
    std::cout << "Carson: ";
    carson->printHand();
    std::cout << "Dylan: ";
    dylan->printHand();

    // New player joins mid-order
    Player* ethan = new Player(5, "Ethan");
    ethan->giveCard(new Card("Blue", "5"));
    ethan->giveCard(new Card("Green", "6"));
    ethan->giveCard(new Card("Green", "Skip"));

    table1->addAnywhere(2, ethan);
    std::cout << std::endl << "-- TURN ORDER AFTER ETHAN JOINS MID-ORDER --" << std::endl;
    table1->print();

    // Alec plays a reverse card
    Card* playedCard = alec->playCard();
    std::cout << std::endl << "*** ALEC PLAYED: " << *playedCard << " ***" << std::endl;
    delete playedCard;
    std::cout << "Alec's new hand: ";
    alec->printHand();
    table1->reverse();
    std::cout << std::endl << "-- TURN ORDER AFTER REVERSE CARD --" << std::endl;
    table1->print();

    // Someone steps away from the table
    table1->deleteAnywhere(3);
    std::cout << std::endl << "-- TURN ORDER AFTER CARSON LEAVES TABLE --" << std::endl;
    table1->print();

    // Form 2nd table
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    Player* fernando = new Player(6, "Fernando");
    fernando->giveCard(new Card("Red", "5"));
    fernando->giveCard(new Card("Yellow", "6"));
    fernando->giveCard(new Card("Green", "7"));

    Player* gilbert = new Player(7, "Gilbert");
    gilbert->giveCard(new Card("Blue", "4"));
    gilbert->giveCard(new Card("Green", "2"));
    gilbert->giveCard(new Card("Red", "4"));

    Player* hael = new Player(8, "Hael");
    hael->giveCard(new Card("Blue", "3"));
    hael->giveCard(new Card("Green", "Reverse"));
    hael->giveCard(new Card("Red", "7"));

    table2->addFront(fernando);
    table2->addFront(gilbert);
    table2->addFront(hael);

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