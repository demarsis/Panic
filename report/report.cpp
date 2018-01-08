#include "report.h"

Report::Report(const QString &filename)
    : filename(filename),
      pdfwriter(filename),
      yPos(0)
{
    pdfwriter.setPageSize(QPagedPaintDevice::A4);
    pdfwriter.setPageMargins(QMargins(PDF_MARGINS, PDF_MARGINS, PDF_MARGINS, PDF_MARGINS));
    painter = new QPainter(&pdfwriter);
}

Report::~Report()
{
    delete painter;
}

void Report::addImage(const QImage &image)
{
    if (image.width() <= 0) return;
    if (image.height() <= 0) return;
    if (pdfwriter.width() <= 0) return;

    float coeff = (float)pdfwriter.width() / (float)image.width();

    QRect rect(0, yPos,
               image.width() * coeff,
               image.height() * coeff);

    painter->drawImage(rect, image);

    yPos += rect.height();
}

void Report::addString(const QString &str, const QFont &font, Qt::AlignmentFlag alignment)
{
    painter->setFont(font);

    QRect rect(0, yPos, pdfwriter.width(), pdfwriter.height());
    painter->drawText(rect, alignment | Qt::TextWordWrap, str);

    QFontMetrics fm(font);
    QRect boundingRect = fm.boundingRect(0, 0, pdfwriter.width(), pdfwriter.height(), Qt::TextWordWrap, str);
    yPos += boundingRect.height();
}
