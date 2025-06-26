#pragma once
#include "Export.h"
#include <QString>
#include <QJsonObject>

namespace CDNProtocol {

class CDNPROTOCOL_EXPORT ProtocolUtils {
public:
    /// сгенерировать уникальный ID
    static QString generateId();

    /// создать шаблон JSON-ошибки { error: { code, message } }
    static QJsonObject createErrorObject(int code, const QString &message);
};

} // namespace CDNProtocol
