#ifndef SIMULATORWIDGET_H
#define SIMULATORWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <QImage>
#include "common/types.h"
#include "common/defines.h"
#include "human/human.h"
#include <math.h>
#include "map/floor.h"
#include "map/mappositions.h"
#include "map/mapbarriers.h"

class SimulatorWidget : public QOpenGLWidget
{
    GLuint floorTextureID;
    FloorPtr floor;

public:
    SimulatorWidget(QWidget *parent = 0);
    ~SimulatorWidget();

    void setFloor(FloorPtr floor);

private:
    void drawFloor();
    void drawFinishPosition(const Position &p);
    void drawBarrier(const Position &p, BarrierType barrierType);
    void drawHuman(HumanPtr human);

    void DrawCircle(float cx, float cy, float r);

    PositionF transferCoordToGl(const PositionF &real_coord) const;
    PositionF transferCoordToGl(const Position &cell_coord) const;

    void setFloorImage(const QImage &image);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
#endif // SIMULATORWIDGET_H
