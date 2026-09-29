//
// Created by alecb on 9/15/2026.
//

#pragma once

#include <iostream>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        // Check if ArrayList is full
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        // Check if position is out of bounds
        if (position < 0 || position > size_) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        // Insertion
        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }
        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        // Check for empty list
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        // Check if position is out of bounds
        if (position < 0 || position > size_ - 1) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        // Deletion and shift
        delete data_[position];
        for (int i = position; i < size_ - 1; i++) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }
    void reverse() override {
        // Check if list is empty or size == 1
        if (size_ <= 1) return;
        // Reverse
        for (int i = 0, j = size_ - 1; i < size_ / 2; i++, j--) {
            T* temp = data_[i];
            data_[i] = data_[j];
            data_[j] = temp;
        }
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};