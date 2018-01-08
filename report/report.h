#ifndef REPORT_H
#define REPORT_H

#include <QString>
#include <QImage>
#include <QPdfWriter>
#include <QPainter>

#define PDF_MARGINS     (100)

class Report
{
    QString filename;
    QPdfWriter pdfwriter;

public:
    Report(const QString &filename);
    void addImage(const QImage &image);
};

#endif // REPORT_H
