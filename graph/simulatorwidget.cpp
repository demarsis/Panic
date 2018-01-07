#include "simulatorwidget.h"

SimulatorWidget::SimulatorWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      humanIconTextures(nullptr),
      floorTexture(nullptr)
{

}

SimulatorWidget::~SimulatorWidget()
{
    makeCurrent();
    if (humanIconTextures) delete humanIconTextures;
    if (floorTexture) delete floorTexture;
    doneCurrent();
}

void SimulatorWidget::setFloor(FloorPtr floor)
{
    this->floor = floor;
    if (floor)
    {
        setFloorImage(floor->getFloorImage()->getImage());
    }

    resize(size().width(), size().height() + 1);
    resize(size().width(), size().height());
}

void SimulatorWidget::drawCircle(GLfloat cx, GLfloat cy, GLfloat r, int num_segments)
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

void SimulatorWidget::drawTexturedRect(GLfloat x, GLfloat y, GLfloat z,
                                       GLfloat width, GLfloat height,
                                       QOpenGLTexture *texturePtr)
{
    if (!texturePtr) return;

    glEnable(GL_TEXTURE_2D);
    texturePtr->bind();
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x - width / 2, y - height / 2, z);
        glTexCoord2f(1, 0); glVertex3f(x + width / 2, y - height / 2, z);
        glTexCoord2f(1, 1); glVertex3f(x + width / 2, y + height / 2, z);
        glTexCoord2f(0, 1); glVertex3f(x - width / 2, y + height / 2, z);
    glEnd();
    glDisable(GL_TEXTURE_2D);
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
    makeCurrent();
    if (floorTexture) delete floorTexture;
    floorTexture = new QOpenGLTexture(image.mirrored());
    doneCurrent();
}

void SimulatorWidget::drawFloor()
{
    float floorWidth  = floor->getSize().x;
    float floorHeight = floor->getSize().y;
    drawTexturedRect(0, 0, 0, floorWidth, floorHeight, floorTexture);
}

void SimulatorWidget::drawFinishPosition(const Position &p)
{
    PositionF pos = transferCoordToGl(p);
    glColor3f(0, 0, 1);
    glLineWidth(2);
    drawCircle(pos.x, pos.y, 4);
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
        drawCircle(pos.x, pos.y, 1);
    }
}

void SimulatorWidget::drawHuman(HumanPtr human)
{
    if (!human) return;
    float diameter = human->getDiameter();

    // transfer position into GL coords
    PositionF pos = transferCoordToGl(human->getPosition());

    // draw human icon
    if (humanIconTextures)
    {
        QOpenGLTexture *tex = humanIconTextures->getTexture(human->getAgeType(), human->getGenderType());
        drawTexturedRect(pos.x, pos.y, 0, diameter, diameter, tex);
    }

    // color: depends on health status
    switch (human->getHealth().getStatus())
    {
    case HealthStatus::Ok:
        glColor3f(0, 0.80f, 0);
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

    // draw circle
    glLineWidth(2);
    drawCircle(pos.x, pos.y, diameter / 2);
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

void SimulatorWidget::drawPenaltyWay()
{
    CellMatrixIterator it = floor->getCellIterator();
    glPointSize(3);
    glBegin(GL_POINTS);
    while (it.hasNext())
    {
        CellPtr cell = it.next();
        if (!cell) continue;

        Penalty color = cell->getAdditionalData().wayPenalty / 600.0f;
        glColor3f(color, color, color);

        PositionF pos = transferCoordToGl(cell->getPosition());
        glVertex3f(pos.x, pos.y, 0);
    }
    glEnd();
    glPointSize(1);
}

void SimulatorWidget::drawPushes()
{
    if (!floor) return;
    MapPushesPtr &pushes = floor->getPushesMap();
    if (!pushes) return;

    int width  = pushes->getSize().x;
    int height = pushes->getSize().y;

    glPointSize(5);
    glBegin(GL_POINTS);
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float push = pushes->getPush(Position(x, y));
            if (push < 10) continue;

            if (push > 50)
            {
                glColor3f(1, 0, 0);
            }
            else if (push > 10)
            {
                glColor3f(1, 1, 0);
            }

            PositionF posf = transferCoordToGl(PositionF(x, y));
            glVertex3f(posf.x + 0.5f, posf.y + 0.5f, 0);
        }
    }
    glEnd();
    glPointSize(1);
}

void SimulatorWidget::initializeGL()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_LINE_SMOOTH);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    humanIconTextures = new HumanIconTextures();
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (!floor) return;

    drawFloor();

    if (DRAW_ADDITION_PLAN_OBJECTS)
    {
        /*for (const Position &p : floor->getFinishMapPositions().getPositionList())
        {
            drawFinishPosition(p);
        }

        for (const auto &barrier : floor->getMapBarriers().getBarrierList())
        {
            drawBarrier(barrier.first, barrier.second);
        }*/

        //drawPenaltyWay();

        drawPushes();
    }

    for (HumanPtr h : floor->getHumanList())
    {
        drawHuman(h);
    }
}

