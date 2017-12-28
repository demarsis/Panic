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
    std::map<std::pair<AgeType, GenderType>, std::shared_ptr<QOpenGLTexture>> textures;

public:
    HumanIconTextures();
    std::shared_ptr<QOpenGLTexture> getTexture(AgeType ageType, GenderType genderType) const;

private:
    void addTexture(AgeType ageType, GenderType genderType, const QString &filename);
};

typedef std::shared_ptr<HumanIconTextures> HumanIconTexturesPtr;


#endif // HUMANICONTEXTURES_H
