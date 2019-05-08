#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H
#include<location.h>
#include<iostream>
#include<memory>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QEventLoop>
#include<suninfo.h>



class WeatherManager
{
    QString str_baseOfUrl {"http://api.sunrise-sunset.org/json?lat="} ;
    QString str_centreOfUrl {"&lng="};
    QString generateUrlForRequest(double lat , double lng );

    Location *ptr_Location;
    QString sunRise;
    QString sunSet;

    std::unique_ptr<QNetworkAccessManager>  ptr_networkManager;
    std::unique_ptr<QNetworkRequest>  ptr_networkRequest;
    std::unique_ptr<QEventLoop>  event_Loop;

    void setSunRise(const QString &value);
    void setSunSet(const QString &value);
    SunInfo result_SI;
public:

    SunInfo getSunInfo(Location *placeInfo );

    WeatherManager();

    WeatherManager(const WeatherManager&) = default;
    WeatherManager& operator=(WeatherManager&) = default;
    ~WeatherManager() = default;

    QString getSunRise() const;
    QString getSunSer() const;

    void setPtr_Location(Location *value);

};

#endif // WEATHERMANAGER_H
