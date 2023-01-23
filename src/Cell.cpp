#include "Cell.h"

#include <QDebug>

Cell::Cell(bool hasBomb)
    : mHasBomb{hasBomb},
      mBombsAround{0} {
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

indexT Cell::bombsAround() const {
    return mBombsAround;
}

void Cell::setBombsAround(indexT bombs) {
    mBombsAround = bombs;
}
