#include "simulatorwidget.h"

SimulatorWidget::SimulatorWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      floorTextureID(0),
      floorTextureSize(0, 0)
{
}

SimulatorWidget::~SimulatorWidget()
{
}

void SimulatorWidget::setFloorImage(const QImage &image)
{
    floorTextureSize.x = image.size().width();
    floorTextureSize.y = image.size().height();

    glEnable(GL_TEXTURE_2D);

    glGenTextures(1, &floorTextureID);
    glBindTexture(GL_TEXTURE_2D, floorTextureID);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage tex = QGLWidget::convertToGLFormat(image);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glDisable(GL_TEXTURE_2D);

    resize(size().width(), size().height() + 1);
    resize(size().width(), size().height());
}

void SimulatorWidget::initializeGL()
{
    glClearColor(0, 0, 0, 1);
}

void SimulatorWidget::resizeGL(int w, int h)
{
    if (h <= 0) return;
    if (w <= 0) return;
    if (floorTextureSize.x <= 0) return;
    if (floorTextureSize.y <= 0) return;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float kScreen = (float)w / (float)h;
    float kImage = (float)floorTextureSize.x / (float)floorTextureSize.y;
    float sizeX, sizeY;
    if (kScreen > kImage)
    {
        sizeX = (float)floorTextureSize.y * (float)w / (float)h;
        sizeY = (float)floorTextureSize.y;
    }
    else
    {
        sizeX = (float)floorTextureSize.x;
        sizeY = (float)floorTextureSize.x * (float)h / (float)w;
    }
    glOrtho(-sizeX / 2, +sizeX / 2,
            -sizeY / 2, +sizeY / 2,
            0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void SimulatorWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floorTextureID);

    glBegin(GL_QUADS);
        float floorWidth  = floorTextureSize.x;
        float floorHeight = floorTextureSize.y;

        glTexCoord2f(0, 0); glVertex3f(-floorWidth / 2, -floorHeight / 2, 0);
        glTexCoord2f(1, 0); glVertex3f(+floorWidth / 2, -floorHeight / 2, 0);
        glTexCoord2f(1, 1); glVertex3f(+floorWidth / 2, +floorHeight / 2, 0);
        glTexCoord2f(0, 1); glVertex3f(-floorWidth / 2, +floorHeight / 2, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

