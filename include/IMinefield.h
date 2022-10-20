#ifndef IMINEFIELD_H
#define IMINEFIELD_H

#include <cstdint>
#include <memory>

class ICell;

class IMinefield {
public:
    virtual ~IMinefield() = default;

    virtual void setDimensions(uint8_t rows, uint8_t columns) = 0;
    virtual void setBombs(uint8_t bombs) = 0;
    virtual std::shared_ptr<ICell> getCell(uint8_t column, uint8_t row) = 0;
};

#endif // IMINEFIELD_H
