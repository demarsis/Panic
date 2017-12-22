#ifndef SIMULATORWIDGET_H
#define SIMULATORWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <QImage>
#include "common/types.h"
#include "human/human.h"

class SimulatorWidget : public QOpenGLWidget
{
    GLuint floorTextureID;
    Size floorTextureSize;
    std::vector<HumanPtr> humanList;

public:
    SimulatorWidget(QWidget *parent = 0);
    ~SimulatorWidget();

    void setFloorImage(const QImage &image);
    void setHumanList(const std::vector<HumanPtr> &humanList);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
#endif // SIMULATORWIDGET_H
