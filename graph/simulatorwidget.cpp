#include "simulatorwidget.h"

SimulatorWidget::SimulatorWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      floorTextureID(0),
      floorSize(0, 0)
{
}

SimulatorWidget::~SimulatorWidget()
{
}

void SimulatorWidget::setFloor(FloorPtr floor)
{
    if (!floor) return;

    setFloorSize(floor->getSize());
    setFloorImage(floor->getFloorImage()->getImage());
    setHumanList(floor->getHumanList());
    setFinishPositionList(floor->getFinishMapPositions());
}

void SimulatorWidget::setFloorSize(const Size &size)
{
    this->floorSize.x = size.x;
    this->floorSize.y = size.y;
}

void SimulatorWidget::DrawCircle(float cx, float cy, float r)
{
    int num_segments = 13;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415f * float(i) / num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex3f(x + cx, y + cy, 0);
    }
    glEnd();
}

PositionF SimulatorWidget::transferCoordToGl(const PositionF &real_coord) const
{
    return PositionF(real_coord.x - floorSize.x / 2,
                     floorSize.y - (floorSize.y / 2 + real_coord.y));
}

PositionF SimulatorWidget::transferCoordToGl(const Position &cell_coord) const
{
    return transferCoordToGl(PositionF(cell_coord.x, cell_coord.y));
}

void SimulatorWidget::setFloorImage(const QImage &image)
{
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

void SimulatorWidget::setHumanList(const std::vector<HumanPtr> &humanList)
{
    this->humanList = humanList;
}

void SimulatorWidget::setFinishPositionList(const MapPositions &mapFinishPosition)
{
    this->finishPositions = mapFinishPosition.getPositionList();
}

void SimulatorWidget::drawFloor()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floorTextureID);

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        float floorWidth  = floorSize.x;
        float floorHeight = floorSize.y;

        glTexCoord2f(0, 0); glVertex3f(-floorWidth / 2, -floorHeight / 2, 0);
        glTexCoord2f(1, 0); glVertex3f(+floorWidth / 2, -floorHeight / 2, 0);
        glTexCoord2f(1, 1); glVertex3f(+floorWidth / 2, +floorHeight / 2, 0);
        glTexCoord2f(0, 1); glVertex3f(-floorWidth / 2, +floorHeight / 2, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void SimulatorWidget::drawFinishPosition(const Position &p)
{
    PositionF pos = transferCoordToGl(p);
    glColor3f(0, 0, 1);
    glLineWidth(2);
    DrawCircle(pos.x, pos.y, 4);
    glLineWidth(1);
}

void SimulatorWidget::drawHuman(HumanPtr human)
{
    if (!human) return;
    float diameter = human->getDiameter() / 10.0f;

    switch (human->getHealth().getStatus())
    {
    case HealthStatus::Ok:
        glColor3f(0, 1, 0);
        break;
    case HealthStatus::MinorDamage:
        glColor3f(1, 1, 0);
        break;
    case HealthStatus::MajorDamage:
        glColor3f(1, 0.5f, 0);
        break;
    case HealthStatus::Dead:
        glColor3f(1, 0, 0);
        break;
    }

    PositionF pos = transferCoordToGl(human->getPosition());

    glLineWidth(2);
    DrawCircle(pos.x, pos.y, diameter);
    glLineWidth(1);

    if (human->getHealth().isDead())
    {
        glBegin(GL_LINES);
            glVertex3f(pos.x - diameter / 2.5f, pos.y - diameter / 2.5f, 0);
            glVertex3f(pos.x + diameter / 2.5f, pos.y + diameter / 2.5f, 0);
            glVertex3f(pos.x - diameter / 2.5f, pos.y + diameter / 2.5f, 0);
            glVertex3f(pos.x + diameter / 2.5f, pos.y - diameter / 2.5f, 0);
        glEnd();
    }
}

void SimulatorWidget::initializeGL()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_LINE_SMOOTH);
}

void SimulatorWidget::resizeGL(int w, int h)
{
    if (h <= 0) return;
    if (w <= 0) return;
    if (floorSize.x <= 0) return;
    if (floorSize.y <= 0) return;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float kScreen = (float)w / (float)h;
    float kImage = (float)floorSize.x / (float)floorSize.y;
    float sizeX, sizeY;
    if (kScreen > kImage)
    {
        sizeX = (float)floorSize.y * (float)w / (float)h;
        sizeY = (float)floorSize.y;
    }
    else
    {
        sizeX = (float)floorSize.x;
        sizeY = (float)floorSize.x * (float)h / (float)w;
    }
    glOrtho(-sizeX / 2, +sizeX / 2,
            -sizeY / 2, +sizeY / 2,
            0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void SimulatorWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawFloor();

    for (const Position &p : finishPositions)
    {
        drawFinishPosition(p);
    }

    for (HumanPtr h : humanList)
    {
        drawHuman(h);
    }
}

