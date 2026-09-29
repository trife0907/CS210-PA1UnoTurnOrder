//
// Created by alecb on 9/17/2026.
//

#pragma once

#include <iostream>
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        // Check if position is out of bounds
        if (position < 0) {
            std::cout << "Not a valid position." << std::endl;
            return;
        }
        Node<T>* fresh = new Node<T>(value);
        Node<T>* current = head_;
        // Check if LinkedList is empty or if position == 0, then add to front
        if (head_ == nullptr || position == 0) {
            fresh->next = head_;
            head_ = fresh;
            return;
        }
        // Insertion for position > 0
        for (int i = 0; i < position - 1; i++) {
            // Account for position > size, stops the loop before going too far down the list
            if (current->next == nullptr) break;
            current = current->next;
        }
        fresh->next = current->next;
        current->next = fresh;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
};