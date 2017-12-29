#ifndef HUMANICONTEXTURES_H
#define HUMANICONTEXTURES_H

#include <map>
#include <human/age.h>
#include <human/gender.h>
#include <QImage>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <memory>
#include <utility>


class HumanIconTextures
{
    std::map<std::pair<AgeType, GenderType>, QOpenGLTexture *> textures;

public:
    HumanIconTextures();
    ~HumanIconTextures();
    QOpenGLTexture *getTexture(AgeType ageType, GenderType genderType) const;

private:
    void addTexture(AgeType ageType, GenderType genderType, const QString &filename);
};


#endif // HUMANICONTEXTURES_H
