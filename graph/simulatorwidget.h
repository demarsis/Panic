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
#include <math.h>

class SimulatorWidget : public QOpenGLWidget
{
    GLuint floorTextureID;
    Size floorSize;
    Size floorTextureSize;
    std::vector<HumanPtr> humanList;

public:
    SimulatorWidget(QWidget *parent = 0);
    ~SimulatorWidget();

    void setFloorSize(const Size &size);
    void setFloorImage(const QImage &image);
    void setHumanList(const std::vector<HumanPtr> &humanList);

private:
    void drawFloor();
    void drawHuman(HumanPtr human);

    void DrawCircle(float cx, float cy, float r);

    PositionF transferCoordToGl(const PositionF &real_coord) const;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
#endif // SIMULATORWIDGET_H
