#include "location.h"

double Location::getLatitude() const
{
    return latitude;
}

void Location::setLatitude(double value)
{
    latitude = value;
}

double Location::getLongitude() const
{
    return longitude;
}

void Location::setLongitude(double value)
{
    longitude = value;
}

QString Location::getPlace() const
{
    return place;
}

void Location::setPlace(const QString &value)
{
    place = value;
}
