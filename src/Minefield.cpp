#include "Minefield.h"

#include <QDebug>
#include <QRandomGenerator>

#include "Cell.h"

Minefield::Minefield(indexT rows, indexT columns, indexT bombs)
    : mRows{rows},
      mColumns{columns},
      mBombs{bombs} {
    qDebug() << "Creating field, rows:" << mRows << ", columns:" << mColumns << ", bombs:" << mBombs;
    initMinefield();
    fillMinefield();
    markCells();
    printMinefield();
}

Minefield::~Minefield()
{
    //qDebug() << "deleting minefield";
}

void Minefield::setDimensions(indexT rows, indexT columns) {
    mRows = rows;
    mColumns = columns;
}

void Minefield::setBombs(indexT bombs) {
    mBombs = bombs;
}

std::shared_ptr<ICell> Minefield::getCell(indexT row, indexT column) {
    return mField.at(mRows * row + column);
}

void Minefield::initMinefield() {
    const auto cells{mRows * mColumns};
    for (auto i = 0; i < cells; i++) {
        mField.push_back(std::make_shared<Cell>(false));
    }
}

void Minefield::fillMinefield() {
    const auto cells{mColumns * mRows};
    indexT bombsSet{0};

    while (bombsSet < mBombs) {
        const auto hasBomb{QRandomGenerator::global()->bounded(2)};
        auto cell{mField.at(QRandomGenerator::global()->bounded(cells))};
        if (hasBomb && !cell->hasBomb()) {
            cell->setHasBomb(true);
            bombsSet++;
        }
    }

    qDebug() <<"bombs set:" << bombsSet << "in" << cells << "cells";
}

void Minefield::printMinefield() {
    QString lineBombs{};
    QString lineBombsAround{};
    for (auto i = 0; i < mRows; i++) {
        for (auto j = 0; j < mColumns; j++) {
            lineBombs += QString::number(static_cast<int>(getCell(i, j)->hasBomb())) + " ";
            lineBombsAround += QString::number(getCell(i, j)->bombsAround()) + " ";
        }
        qDebug() << lineBombs << "\t" << lineBombsAround;
        lineBombs.clear();
        lineBombsAround.clear();
    }
}

void Minefield::checkBombsAround(indexT row, indexT column) {
    indexT bombs{0};
    if (row == 0) {
        // top line
        if (column == 0) {
            // top left cell
            bombs = static_cast<decltype (bombs)>(getCell(row, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column)->hasBomb());
        } else if (column == (mColumns - 1)) {
            // top right cell
            bombs = static_cast<decltype (bombs)>(getCell(row, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column)->hasBomb());
        } else {
            // top middle cell
            bombs = static_cast<decltype (bombs)>(getCell(row, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column + 1)->hasBomb());
        }
    } else if (row == (mRows - 1)) {
        // bottom line
        if (column == 0) {
            // bottom left cell
            bombs = static_cast<decltype (bombs)>(getCell(row - 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column + 1)->hasBomb());
        } else if (column == (mColumns - 1)) {
            // bottom right cell
            bombs = static_cast<decltype (bombs)>(getCell(row - 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column - 1)->hasBomb());
        } else {
            // bottom middle cell
            bombs = static_cast<decltype (bombs)>(getCell(row - 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column + 1)->hasBomb());
        }
    } else {
        // somewhere in the middle
        if (column == 0) {
            // middle left cell
            bombs = static_cast<decltype (bombs)>(getCell(row - 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column + 1)->hasBomb());
        } else if (column == (mColumns - 1)) {
            // middle right cell
            bombs = static_cast<decltype (bombs)>(getCell(row - 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column)->hasBomb());
        } else {
            // just somewhere in the middle
            bombs = static_cast<decltype (bombs)>(getCell(row - 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row - 1, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row, column + 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column - 1)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column)->hasBomb())
                    + static_cast<decltype (bombs)>(getCell(row + 1, column + 1)->hasBomb());
        }
    }
    getCell(row, column)->setBombsAround(bombs);
}

void Minefield::markCells() {
    for (auto i = 0; i < mRows; i++) {
        for (auto j = 0; j < mColumns; j++) {
            checkBombsAround(i, j);
        }
    }
}



