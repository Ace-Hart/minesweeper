#ifndef IMINEFIELD_H
#define IMINEFIELD_H

#include <memory>

#include "Common.h"

class ICell;

class IMinefield {
public:
    virtual ~IMinefield() = default;

    virtual void setDimensions(indexT rows, indexT columns) = 0;
    virtual void setBombs(indexT bombs) = 0;
    virtual std::shared_ptr<ICell> getCell(indexT column, indexT row) = 0;
};

#endif // IMINEFIELD_H
