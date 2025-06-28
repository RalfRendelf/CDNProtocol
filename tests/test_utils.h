
#pragma once

#include <QTest>
#include <QByteArray>
#include "CDNProtocol/CommandEnums.h"

namespace QTest {
inline QDebug operator<<(QDebug dbg, CDNProtocol::Command cmd) {
    return dbg << CDNProtocol::toString(cmd);
}
}
