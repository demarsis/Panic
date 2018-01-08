#include "report.h"

Report::Report(const QString &filename)
    : filename(filename),
      pdfwriter(filename)
{
    pdfwriter.setPageSize(QPagedPaintDevice::A4);
    pdfwriter.setPageMargins(QMargins(PDF_MARGINS, PDF_MARGINS, PDF_MARGINS, PDF_MARGINS));
}

void Report::addImage(const QImage &image)
{
    if (image.width() <= 0) return;
    if (image.height() <= 0) return;
    if (pdfwriter.width() <= 0) return;

    QPainter painter(&pdfwriter);
    float coeff = (float)pdfwriter.width() / (float)image.width();

    QRect rect(0, 0,
               image.width() * coeff,
               image.height() * coeff);

    painter.drawImage(rect, image);
}
