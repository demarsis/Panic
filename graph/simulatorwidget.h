#ifndef SIMULATORWIDGET_H
#define SIMULATORWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QGLWidget>
#include <QOpenGLTexture>
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
#include "common/consolelogger.h"
#include "humanicontextures.h"

typedef std::shared_ptr<QOpenGLTexture> TexturePtr;

class SimulatorWidget : public QOpenGLWidget
{
    FloorPtr floor;

    HumanIconTexturesPtr humanIconTextures;
    TexturePtr floorTexture;

public:
    SimulatorWidget(QWidget *parent = 0);

    void setFloor(FloorPtr floor);

private:
    void drawFloor();
    void drawFinishPosition(const Position &p);
    void drawBarrier(const Position &p, BarrierType barrierType);
    void drawHuman(HumanPtr human);

    void drawCircle(GLfloat cx, GLfloat cy, GLfloat r, int num_segments = 13);
    void drawTexturedRect(GLfloat x, GLfloat y, GLfloat z,
                          GLfloat width, GLfloat height,
                          TexturePtr texturePtr);

    PositionF transferCoordToGl(const PositionF &real_coord) const;
    PositionF transferCoordToGl(const Position &cell_coord) const;

    void setFloorImage(const QImage &image);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
#endif // SIMULATORWIDGET_H
