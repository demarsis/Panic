#ifndef REPORT_H
#define REPORT_H

#include <QString>
#include <QImage>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QFontMetrics>

#define PDF_MARGINS     (80)

class Report
{
    QString filename;
    QPdfWriter pdfwriter;
    QPainter *painter;
    int yPos;

public:
    Report(const QString &filename);
    ~Report();
    void addImage(const QImage &image);
    void addString(const QString &str, const QFont &font, Qt::AlignmentFlag alignment);
};

#endif // REPORT_H
