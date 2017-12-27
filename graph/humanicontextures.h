#ifndef HUMANICONTEXTURES_H
#define HUMANICONTEXTURES_H

#include <map>
#include <human/age.h>
#include <human/gender.h>
#include <QImage>
#include <QGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <utility>

class HumanIconTextures
{
    std::map<std::pair<AgeType, GenderType>, GLuint> textures;

public:
    HumanIconTextures();
    ~HumanIconTextures();

    GLuint getTextureID(AgeType ageType, GenderType genderType) const;

private:
    QImage loadImageFromFile(const QString &filename);
    GLuint imageToTexture(const QImage &imageGLFormat) const;

    void addTexture(AgeType ageType, GenderType genderType, const QString &filename);
    void freeTexture(GLuint textureID);
};

typedef std::shared_ptr<HumanIconTextures> HumanIconTexturesPtr;

#endif // HUMANICONTEXTURES_H
