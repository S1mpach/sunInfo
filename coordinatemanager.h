#ifndef COORDINATEMANAGER_H
#define COORDINATEMANAGER_H
#include<iostream>
#include<memory>
#include<location.h>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QEventLoop>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

class CoordinateManager
{
public:
    CoordinateManager() : ptr_Location(new Location) , ptr_networkManager(new QNetworkAccessManager),
        ptr_networkRequest(new QNetworkRequest) , eventLoop(new QEventLoop)
    {}

    virtual ~CoordinateManager(){}

    Location* getPtr_Location() const
    {
        return ptr_Location;
    }

protected:


    virtual void getCoordinate() = 0;







    Location *ptr_Location;
    std::unique_ptr<QNetworkAccessManager>  ptr_networkManager;
    std::unique_ptr<QNetworkRequest>  ptr_networkRequest;
    std::unique_ptr<QEventLoop> eventLoop;
};

#endif // COORDINATEMANAGER_H

