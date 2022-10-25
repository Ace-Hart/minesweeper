#ifndef MINEFIELD_H
#define MINEFIELD_H

#include "IMinefield.h"

#include <vector>

#include "ICell.h"

class Minefield final : public IMinefield
{
public:
    Minefield(uint8_t rows, uint8_t columns, uint8_t bombs);
    ~Minefield();

    void setDimensions(uint8_t rows, uint8_t columns) override;
    void setBombs(uint8_t bombs) override;
    std::shared_ptr<ICell> getCell(uint8_t column, uint8_t row) override;

private:
    void fillMinefield();
    void printMinefield();

    uint8_t mRows;
    uint8_t mColumns;
    uint8_t mBombs;

    std::vector<std::shared_ptr<ICell>> mField;
};

#endif // MINEFIELD_H
