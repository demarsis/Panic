#include "cellmatrix.h"


CellMatrixIterator::CellMatrixIterator(CellMatrix &matrix)
    : matrix(matrix),
      x(0), y(0)
{
}

bool CellMatrixIterator::hasNext() const
{
    // not last x position
    if (x < matrix.size() - 1) return true;
    if (x >= matrix.size()) return false;

    // last x position, not last y position
    if (y < matrix[x].size()) return true;

    // no more values
    return false;
}

CellPtr CellMatrixIterator::next()
{
    CellPtr result = matrix[x][y];

    y++;
    if (y >= matrix[x].size())
    {
        y = 0;
        x++;
    }

    return result;
}

void CellMatrixIterator::reset()
{
    x = 0;
    y = 0;
}
