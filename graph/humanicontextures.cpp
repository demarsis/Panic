#include "humanicontextures.h"

HumanIconTextures::HumanIconTextures()
{
    addTexture(AgeTypeChild,    GenderTypeMale,    "textures\\people\\child-male.png");
    addTexture(AgeTypeChild,    GenderTypeFemale,  "textures\\people\\child-female.png");

    addTexture(AgeTypeAdult,    GenderTypeMale,    "textures\\people\\adult-male.png");
    addTexture(AgeTypeAdult,    GenderTypeFemale,  "textures\\people\\adult-female.png");

    addTexture(AgeTypeElderly,  GenderTypeMale,    "textures\\people\\elderly-male.png");
    addTexture(AgeTypeElderly,  GenderTypeFemale,  "textures\\people\\elderly-female.png");
}

HumanIconTextures::~HumanIconTextures()
{
    // remove all textures from GPU
    for (auto iterator : textures)
    {
        freeTexture(iterator.second);
    }
}

GLuint HumanIconTextures::getTextureID(AgeType ageType, GenderType genderType) const
{
    return textures.at(std::make_pair(ageType, genderType));
}

QImage HumanIconTextures::loadImageFromFile(const QString &filename)
{
    QImage img(filename);
    return QGLWidget::convertToGLFormat(img);
}

GLuint HumanIconTextures::imageToTexture(const QImage &imageGLFormat) const
{
    GLuint result;

    glEnable(GL_TEXTURE_2D);

    glGenTextures(1, &result);
    glBindTexture(GL_TEXTURE_2D, result);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageGLFormat.width(), imageGLFormat.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, imageGLFormat.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glDisable(GL_TEXTURE_2D);

    return result;
}

void HumanIconTextures::addTexture(AgeType ageType, GenderType genderType, const QString &filename)
{
    textures[std::make_pair(ageType, genderType)] =
            imageToTexture(loadImageFromFile(filename));

}

void HumanIconTextures::freeTexture(GLuint textureID)
{
    glDeleteTextures(1, &textureID);
}

