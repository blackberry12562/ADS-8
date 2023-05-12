// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0), real(first) {}
void Train::addCage(bool light) {
    if (first == nullptr) {
        first = create(light);
        real = first;
    } else {
        Cage* cage = create(light);
        real->next = cage;
        cage->prev = real;
        cage->next = first;
        first->prev = cage;
        real = cage;
    }
}
int Train::getLength() {
    Cage* rea = first;
    int count_ = 0;
    if (first->light == false)
        first->light = true;
    rea = rea->next;
    while (rea) {
        countOp++;
        if (rea->light == false) {
            count_++;
        } else {
            count_++;
            rea->light = false;
            countOp += count_;
            for (int i = 0; i < count_; i++) {
                rea = rea->prev;
            }
            if (rea->light == false) {
                break;
            } else {
                countOp += count_;
                for (int i = 0; i < count_; i++) {
                    rea = rea->next;
                }
            }
        }
        rea = rea->next;
    }
    return count_;
}
int Train::getOpCount() {
    return countOp;
}
