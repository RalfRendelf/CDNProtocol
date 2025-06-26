#include "CDNProtocol/ProtocolMessage.h"
#include "CDNProtocol/CommandEnums.h"
#include <QJsonObject>
#include <QJsonValue>

using namespace CDNProtocol;

ProtocolMessage ProtocolMessage::fromJson(const QJsonObject &obj) {
    ProtocolMessage msg;
    msg.id      = obj.value("id").toString();
    msg.from    = obj.value("from").toString();
    msg.to      = obj.value("to").toString();
    auto actStr = obj.value("action").toString();
    auto actOpt = fromString(actStr);
    msg.action  = actOpt.value_or(Command::Ping);
    msg.payload = obj.value("payload").toObject();
    msg.response= obj.value("response").toObject();
    return msg;
}

QJsonObject ProtocolMessage::toJson() const {
    QJsonObject obj;
    obj["id"]       = id;
    obj["from"]     = from;
    obj["to"]       = to;
    obj["action"]   = toString(action);
    obj["payload"]  = payload;
    obj["response"] = response;
    return obj;
}

bool ProtocolMessage::validate(QString &error) const {
    if (id.isEmpty())    { error = "Missing 'id'";      return false; }
    if (from.isEmpty())  { error = "Missing 'from'";    return false; }
    if (to.isEmpty())    { error = "Missing 'to'";      return false; }
    if (toString(action).isEmpty()) { error = "Invalid 'action'"; return false; }
    return true;
}
