#pragma once

#include <QtTest>
#include "CDNProtocol/ProtocolMessage.h"
#include "CDNProtocol/ProtocolUtils.h"
#include "test_utils.h"  // обязательно содержит operator<< для Command

using namespace CDNProtocol;

class ProtocolMessageTest : public QObject {
    Q_OBJECT

private slots:
    void test_toFromJson() {
        ProtocolMessage msg;
        msg.id       = ProtocolUtils::generateId();
        msg.from     = "web";
        msg.to       = "central";
        msg.action   = Command::StatusReport;
        msg.payload  = QJsonObject{{"foo", 42}};
        msg.response = QJsonObject{{"bar", "ok"}};

        const QJsonObject json = msg.toJson();
        const ProtocolMessage restored = ProtocolMessage::fromJson(json);

        QVERIFY(restored.id == msg.id);
        QCOMPARE(restored.from,     msg.from);
        QCOMPARE(restored.to,       msg.to);
        QVERIFY(restored.action == msg.action);  // чтобы обойти проблемы с QCOMPARE
        QCOMPARE(restored.payload,  msg.payload);
        QCOMPARE(restored.response, msg.response);
    }

    void test_validate() {
        ProtocolMessage msg;
        QString err;

        QVERIFY(!msg.validate(err));
        QCOMPARE(err, QString("Missing 'id'"));

        msg.id = ProtocolUtils::generateId();
        QVERIFY(!msg.validate(err));
        QCOMPARE(err, QString("Missing 'from'"));

        msg.from   = "web";
        msg.to     = "central";
        msg.action = static_cast<Command>(-1);  // заведомо невалидный
        QVERIFY(!msg.validate(err));
        QCOMPARE(err, QString("Invalid 'action'"));

        msg.action = Command::Ping;
        QVERIFY(msg.validate(err));
    }
};

QTEST_MAIN(ProtocolMessageTest)
#include "test_ProtocolMessage.moc"
