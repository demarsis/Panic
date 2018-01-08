#ifndef REPORT_H
#define REPORT_H

#include <QString>
#include <QImage>
#include <QPdfWriter>
#include <QPainter>

class Report
{
    QString filename;
    QPdfWriter writer;

public:
    Report(const QString &filename);
    void addImage(const QImage &image);
};

#endif // REPORT_H
