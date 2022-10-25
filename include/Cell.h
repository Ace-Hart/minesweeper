#ifndef CELL_H
#define CELL_H

#include "ICell.h"

class Cell final : public ICell
{
public:
    Cell(bool hasBomb);
    ~Cell();// = default;

    bool hasBomb() const override;
    void setHasBomb(bool hasBomb) override;

    uint8_t bombsAround() const override;
    void setBombsAround(uint8_t bombs) override;

private:
    bool mHasBomb;
    uint8_t mBombsAround;
};

#endif // CELL_H
