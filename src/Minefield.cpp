#include "Minefield.h"

#include <QDebug>

#include "Cell.h"

Minefield::Minefield(uint8_t rows, uint8_t columns, uint8_t bombs)
    : mRows{rows},
      mColumns{columns},
      mBombs{bombs} {
    qDebug() << "Creating field, rows:" << mRows << ", columns:" << mColumns << ", bombs:" << mBombs;
    fillMinefield();
    printMinefield();
}

Minefield::~Minefield()
{
    //qDebug() << "deleting minefield";
}

void Minefield::setDimensions(uint8_t rows, uint8_t columns) {
    mRows = rows;
    mColumns = columns;
}

void Minefield::setBombs(uint8_t bombs) {
    mBombs = bombs;
}

std::shared_ptr<ICell> Minefield::getCell(uint8_t row, uint8_t column) {
    return mField.at(mRows * row + column);
}

void Minefield::printMinefield() {
    QString line{};
    for (auto i = 0; i < mRows; i++) {
        for (auto j = 0; j < mColumns; j++) {
            line += QString::number(static_cast<int>(getCell(i, j)->hasBomb())) + " ";
        }
        qDebug() << line;
        line.clear();
    }
}

void Minefield::fillMinefield() {
    uint8_t bombs{0};
    uint8_t cells{0};
    const auto step{(mColumns * mRows) / mBombs};
    qDebug() << "step = " << step;
    for (auto i = 0; i < mRows; i++) {
        for (auto j = 0; j < mColumns; j++) {
            //TODO: replace with actual random
            cells++;
            if ((cells % step) == 0) {
                mField.push_back(std::make_shared<Cell>(true));
                bombs++;
            } else {
                mField.push_back(std::make_shared<Cell>(false));
            }
        }
    }
    qDebug() <<"bombs set:" << bombs << "in" << cells << "cells";
}

