#ifndef CELL_H
#define CELL_H

#include "ICell.h"

#include "Common.h"

class Cell final : public ICell
{
public:
    Cell(bool hasBomb);
    ~Cell();// = default;

    bool hasBomb() const override;
    void setHasBomb(bool hasBomb) override;

    indexT bombsAround() const override;
    void setBombsAround(indexT bombs) override;

private:
    bool mHasBomb;
    indexT mBombsAround;
};

#endif // CELL_H
