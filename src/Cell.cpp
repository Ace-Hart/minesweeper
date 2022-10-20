#include "Cell.h"

#include <QDebug>

Cell::Cell(uint8_t bombs) : mBombsAround{bombs} {
    //qDebug() << "Creating cell " << mBombsAround;
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
