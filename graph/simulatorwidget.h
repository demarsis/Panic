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
#include "map/floor.h"

class SimulatorWidget : public QOpenGLWidget
{
    GLuint floorTextureID;
    Size floorSize;
    std::vector<HumanPtr> humanList;
    std::vector<Position> finishPositions;

public:
    SimulatorWidget(QWidget *parent = 0);
    ~SimulatorWidget();

    void setFloor(FloorPtr floor);

private:
    void setFloorSize(const Size &size);
    void setFloorImage(const QImage &image);
    void setHumanList(const std::vector<HumanPtr> &humanList);
    void setFinishPositionList(const MapPositions &mapFinishPosition);

private:
    void drawFloor();
    void drawFinishPosition(const Position &p);
    void drawHuman(HumanPtr human);

    void DrawCircle(float cx, float cy, float r);

    PositionF transferCoordToGl(const PositionF &real_coord) const;
    PositionF transferCoordToGl(const Position &cell_coord) const;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
#endif // SIMULATORWIDGET_H
