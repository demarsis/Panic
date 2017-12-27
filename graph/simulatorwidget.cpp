#include "simulatorwidget.h"

SimulatorWidget::SimulatorWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      floorTextureID(0)
{
}

SimulatorWidget::~SimulatorWidget()
{
}

void SimulatorWidget::setFloor(FloorPtr floor)
{
    this->floor = floor;
    if (floor)
    {
        setFloorImage(floor->getFloorImage()->getImage());
    }
}

void SimulatorWidget::DrawCircle(float cx, float cy, float r, int num_segments)
{
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
    if (!floor) return PositionF(0, 0);
    Size floorSize = floor->getSize();
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

void SimulatorWidget::drawFloor()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floorTextureID);

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        float floorWidth  = floor->getSize().x;
        float floorHeight = floor->getSize().y;

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

void SimulatorWidget::drawBarrier(const Position &p, BarrierType barrierType)
{
    PositionF pos = transferCoordToGl(p);

    switch (barrierType)
    {
    case BarrierTypeNo:
        break;
    case BarrierTypeCritical:
        glColor3f(1, 0, 0);
        break;
    case BarrierTypeWall:
        glColor3f(0, 0, 0);
        break;
    }

    if (barrierType != BarrierTypeNo)
    {
        DrawCircle(pos.x, pos.y, 1);
    }
}

void SimulatorWidget::drawHuman(HumanPtr human)
{
    if (!human) return;
    float diameter = human->getDiameter() / 10.0f;

    // color: depends on health status
    switch (human->getHealth().getStatus())
    {
    case HealthStatus::Ok:
        glColor3f(0, 0.75f, 0);
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

    // transfer position into GL coords
    PositionF pos = transferCoordToGl(human->getPosition());

    // draw human icon
    if (humanIconTextures)
    {
        glEnable(GL_TEXTURE_2D);
        GLuint humanIconTexutureID = humanIconTextures->getTextureID(human->getAgeType(), human->getGenderType());
        glBindTexture(GL_TEXTURE_2D, humanIconTexutureID);
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
            const float diameterCoeff = 1.3f;
            glTexCoord2f(0, 0); glVertex3f(pos.x - diameter / diameterCoeff, pos.y - diameter / diameterCoeff, 0);
            glTexCoord2f(1, 0); glVertex3f(pos.x + diameter / diameterCoeff, pos.y - diameter / diameterCoeff, 0);
            glTexCoord2f(1, 1); glVertex3f(pos.x + diameter / diameterCoeff, pos.y + diameter / diameterCoeff, 0);
            glTexCoord2f(0, 1); glVertex3f(pos.x - diameter / diameterCoeff, pos.y + diameter / diameterCoeff, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    // draw circle
    glLineWidth(2);
    DrawCircle(pos.x, pos.y, diameter);
    glLineWidth(1);

    // dead cross status
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

    humanIconTextures = std::make_shared<HumanIconTextures>();
}

void SimulatorWidget::resizeGL(int w, int h)
{
    Size floorSize(0, 0);
    if (floor)
    {
        floorSize = floor->getSize();
    }

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
    if (!floor) return;

    drawFloor();

    if (DRAW_ADDITION_PLAN_OBJECTS)
    {
        for (const Position &p : floor->getFinishMapPositions().getPositionList())
        {
            drawFinishPosition(p);
        }

        for (const auto &barrier : floor->getMapBarriers().getBarrierList())
        {
            drawBarrier(barrier.first, barrier.second);
        }
    }

    for (HumanPtr h : floor->getHumanList())
    {
        drawHuman(h);
    }
}

