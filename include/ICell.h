#ifndef ICELL_H
#define ICELL_H

#include <cstdint>

class ICell {
public:
    virtual ~ICell() = default;

    virtual bool hasBomb() const = 0;
    virtual void setHasBomb(bool hasBomb) = 0;

    virtual uint8_t bombsAround() const = 0;
    virtual void setBombsAround(uint8_t bombs) = 0;
};

#endif // ICELL_H
