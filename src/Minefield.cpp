#include "Minefield.h"

#include <QDebug>

#include "Cell.h"

Minefield::Minefield(uint8_t rows, uint8_t columns, uint8_t bombs)
    : mRows{rows},
      mColumns{columns},
      mBombs{bombs} {
    fillMinefield();
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

void Minefield::fillMinefield() {
    auto k{0};
    for (auto i = 0; i < mColumns; i++) {
        for (auto j = 0; j < mRows; j++) {
            const auto value{(QString::number(i)) + QString::number(j)};
            //qDebug() << value;
            mField.push_back(std::make_shared<Cell>(value.toUInt()));
            k++;
        }
    }
}

