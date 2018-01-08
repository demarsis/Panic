#include "report.h"

Report::Report(const QString &filename)
    : filename(filename),
      writer(filename)
{
}

void Report::addImage(const QImage &image)
{
    writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times", 10));

    QRect r = painter.viewport();

    QString citydate = "City";

    painter.drawText(r, Qt::AlignRight, citydate);
}
