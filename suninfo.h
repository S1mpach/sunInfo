#ifndef SUNINFO_H
#define SUNINFO_H
#include<QString>

class SunInfo
{
    QString placeName;
    QString sunSet;
    QString sunRise;

public:

    SunInfo()=default;

    QString getPlaceName() const
    {
        return placeName;
    }
    void setPlaceName(const QString &value)
    {
        placeName = value;
    }


    QString getSunSet() const
    {
        return sunSet;
    }

    void setSunSet(const QString &value)
    {
        sunSet = value;
    }
    QString getSunRise() const
    {
        return sunRise;
    }
    void setSunRise(const QString &value)
    {
        sunRise = value;
    }
};



#endif // SUNINFO_H








