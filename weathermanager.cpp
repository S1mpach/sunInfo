#include "weathermanager.h"

WeatherManager::WeatherManager():ptr_Location(new Location) , ptr_networkManager(new QNetworkAccessManager),
    ptr_networkRequest(new QNetworkRequest) , event_Loop(new QEventLoop){

    QObject::connect(ptr_networkManager.get(), &QNetworkAccessManager::finished,
                     [&](QNetworkReply *reply)
    {

        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Got some error " << reply->error();

        }else {

            const int resultCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug() << "Received code :" << resultCode;
            if (resultCode == 200)
            {
                QString strReply = QString::fromStdString( reply->readAll().toStdString() );

                QJsonDocument jsonResponse = QJsonDocument::fromJson( strReply.toUtf8() );

                QJsonObject responseObject = jsonResponse.object();

                QJsonObject results_Object = responseObject.value("results").toObject();

                result_SI.setSunRise(results_Object.value("sunrise").toString());
                result_SI.setSunSet(results_Object.value("sunset").toString());
                result_SI.setPlaceName(ptr_Location->getPlace());
                qDebug()<<"WEATHER";
                qDebug()<<result_SI.getSunSet();
                qDebug()<<result_SI.getSunRise();
                qDebug()<<result_SI.getPlaceName();
            }
        }
        reply->deleteLater();
    }
    );
    QObject::connect(ptr_networkManager.get(), SIGNAL(finished(QNetworkReply*)),event_Loop.get(), SLOT(quit()));

}

QString WeatherManager::getSunSer() const
{
    return sunSet;
}

QString WeatherManager::generateUrlForRequest(double lat, double lng)
{
    return  str_baseOfUrl + QString::number(lat,'f',8) + str_centreOfUrl + QString::number(lng,'f',8) ;
}

void WeatherManager::setSunSet(const QString &value)
{
    sunSet = value;
}

void WeatherManager::setSunRise(const QString &value)
{
    sunRise = value;
}

void WeatherManager::setPtr_Location( Location *value)
{
    ptr_Location = value;
}

SunInfo WeatherManager::getSunInfo(Location *placeInfo)
{

    ptr_Location = placeInfo;



    ptr_networkRequest->setUrl( generateUrlForRequest(ptr_Location->getLatitude() , ptr_Location->getLongitude()) );

    qDebug()<<generateUrlForRequest(ptr_Location->getLatitude() , ptr_Location->getLongitude());
    ptr_networkManager->get(*ptr_networkRequest);

    event_Loop->exec();

    return result_SI;

}

QString WeatherManager::getSunRise() const
{
    return sunRise;
}
