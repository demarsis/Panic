#ifndef CELLMATRIX_H
#define CELLMATRIX_H

#include "cell.h"
#include <vector>

typedef std::vector<std::vector<CellPtr>> CellMatrix;

class CellMatrixIterator
{
    CellMatrix &matrix;

    // current position
    size_t x, y;

public:
    CellMatrixIterator(CellMatrix &matrix);

    bool hasNext() const;
    CellPtr &next();

    void reset();
};

#endif // CELLMATRIX_H
