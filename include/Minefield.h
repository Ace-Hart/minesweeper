#ifndef MINEFIELD_H
#define MINEFIELD_H

#include "IMinefield.h"

#include <vector>

#include "ICell.h"

class Minefield final : public IMinefield
{
public:
    Minefield(indexT rows, indexT columns, indexT bombs);
    ~Minefield();

    void setDimensions(indexT rows, indexT columns) override;
    void setBombs(indexT bombs) override;
    std::shared_ptr<ICell> getCell(indexT column, indexT row) override;

private:
    void initMinefield();
    void fillMinefield();
    void printMinefield();
    void checkBombsAround(indexT row, indexT column);
    void markCells();

    indexT mRows;
    indexT mColumns;
    indexT mBombs;

    std::vector<std::shared_ptr<ICell>> mField;
};

#endif // MINEFIELD_H
