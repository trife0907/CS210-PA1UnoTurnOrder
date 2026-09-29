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
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        size_++;
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
        size_--;
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
        if (position < 0 || position > size_) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        Node<T>* fresh = new Node<T>(value);
        Node<T>* current = head_;
        // Check if LinkedList is empty or if position == 0, then add to front
        if (size_ == 0 || position == 0) {
            fresh->next = head_;
            head_ = fresh;
            size_++;
            return;
        }
        // Insertion for position > 0
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        fresh->next = current->next;
        current->next = fresh;
        size_++;
    }

    void deleteAnywhere(int position) override {
        // Check for empty list
        if (size_ == 0) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        // Check if position is out of bounds
        if (position < 0 || position > size_ - 1) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        // Check if size == 1 or position == 0, then delete from front
        if (size_ == 1 || position == 0) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
            size_--;
            return;
        }
        // Deletion for position > 0
        Node<T>* current = head_;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node<T>* doomed = current->next;
        current->next = doomed->next;
        delete doomed->data;
        delete doomed;
        size_--;
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
    int size_;
};