#ifndef CELLMATRIX_H
#define CELLMATRIX_H

#include "cell.h"
#include <vector>
//#include "common/"

typedef std::vector<std::vector<CellPtr>> CellMatrix;

/*class CellMatrix : public std::vector<std::vector<CellPtr>>
{
};*/

class CellMatrixIterator
{
    CellMatrix &matrix;

    // current position
    size_t x, y;

public:
    CellMatrixIterator(CellMatrix &matrix);

    bool hasNext() const;
    CellPtr next();
};

#endif // CELLMATRIX_H
