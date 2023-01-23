#ifndef ICELL_H
#define ICELL_H

#include "Common.h"

class ICell {
public:
    virtual ~ICell() = default;

    virtual bool hasBomb() const = 0;
    virtual void setHasBomb(bool hasBomb) = 0;

    virtual indexT bombsAround() const = 0;
    virtual void setBombsAround(indexT bombs) = 0;
};

#endif // ICELL_H
