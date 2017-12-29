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
    for (auto tex : textures)
    {
        delete tex.second;
    }
}

QOpenGLTexture *HumanIconTextures::getTexture(AgeType ageType, GenderType genderType) const
{
    return textures.at(std::make_pair(ageType, genderType));
}

void HumanIconTextures::addTexture(AgeType ageType, GenderType genderType, const QString &filename)
{
    textures[std::make_pair(ageType, genderType)] =
            new QOpenGLTexture(QImage(QString(filename)).mirrored());

}
