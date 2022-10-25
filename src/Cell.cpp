#include "Cell.h"

#include <QDebug>

Cell::Cell(bool hasBomb) : mHasBomb{hasBomb} {
    //qDebug() << "Creating cell " << mHasBomb;
}

Cell::~Cell() {
    //qDebug() << "Deleting cell" << mBombsAround;
}

bool Cell::hasBomb() const {
    return mHasBomb;
}

void Cell::setHasBomb(bool hasBomb){
    mHasBomb = hasBomb;
}

uint8_t Cell::bombsAround() const {
    return mBombsAround;
}

void Cell::setBombsAround(uint8_t bombs) {
    mBombsAround = bombs;
}
