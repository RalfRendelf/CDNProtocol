#pragma once
#include "Export.h"
#include "CommandEnums.h"
#include <QString>
#include <QJsonObject>

namespace CDNProtocol {

struct CDNPROTOCOL_EXPORT ProtocolMessage {
    QString     id;
    QString     from;
    QString     to;
    Command     action;
    QJsonObject payload;
    QJsonObject response;

    ProtocolMessage() = default;

    static ProtocolMessage fromJson(const QJsonObject& obj);
    QJsonObject toJson() const;
    bool validate(QString &error) const;
};

} // namespace CDNProtocol
