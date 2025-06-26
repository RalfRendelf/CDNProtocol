#include "CDNProtocol/ProtocolUtils.h"
#include <QUuid>
#include <QJsonObject>

using namespace CDNProtocol;

QString ProtocolUtils::generateId() {
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}

QJsonObject ProtocolUtils::createErrorObject(int code, const QString &message) {
    QJsonObject err;
    err["code"]    = code;
    err["message"] = message;
    QJsonObject wrapper;
    wrapper["error"] = err;
    return wrapper;
}
