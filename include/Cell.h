#ifndef CELL_H
#define CELL_H

#include "ICell.h"

class Cell final : public ICell
{
public:
    Cell(uint8_t bombs);
    ~Cell();// = default;

    bool hasBomb() const;
    void setHasBomb(bool hasBomb);

    uint8_t bombsAround() const;
    void setBombsAround(uint8_t bombs);

private:
    bool mHasBomb;
    uint8_t mBombsAround;
};

#endif // CELL_H
