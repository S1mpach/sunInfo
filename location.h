#ifndef LOCATION_H
#define LOCATION_H
#include<iostream>
#include<QString>
class Location
{
    QString place;
    double latitude;
    double longitude;


public:
    Location(QString placeName , double latit , double longit)
        :place(placeName),latitude(latit),longitude(longit)
    {}

    Location() = default;
    Location(double lat,double lng , QString placeName)
        :place(placeName),latitude(lat),longitude(lng)
    {}
    Location(const Location&) = default;
    Location& operator=(Location&) = default;


    QString getPlace() const;
    void setPlace(const QString &value);
    double getLatitude() const;
    void setLatitude(double value);
    double getLongitude() const;
    void setLongitude(double value);
};

#endif // LOCATION_H
