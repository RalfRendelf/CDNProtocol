
#include <QtTest>
#include "CDNProtocol/CommandRegistry.h"
#include "test_utils.h"

using namespace CDNProtocol;

class CommandRegistryTest : public QObject {
    Q_OBJECT
private slots:
    void test_commandsForRole_data() {
        QTest::addColumn<Role>("role");
        QTest::addColumn<int>("expectedCount");

        QTest::newRow("web")      << Role::Web      << 4;
        QTest::newRow("adminUI")  << Role::AdminUI  << 10;
        QTest::newRow("db")       << Role::Db       << 6;
        QTest::newRow("generator")<< Role::Generator<< 2;
        QTest::newRow("central")  << Role::Central  << 3;
    }
    void test_commandsForRole() {
        QFETCH(Role, role);
        QFETCH(int, expectedCount);
        auto cmds = CommandRegistry::commandsForRole(role);
        QCOMPARE(cmds.size(), expectedCount);
    }

    void test_isAllowed() {
        QVERIFY(CommandRegistry::isAllowed(Role::AdminUI, Command::Shutdown));
        QVERIFY(!CommandRegistry::isAllowed(Role::Web, Command::Shutdown));
    }

    void test_commandInfosForRole() {
        auto infos = CommandRegistry::commandInfosForRole(Role::Web);
        QCOMPARE(infos.size(), CommandRegistry::commandsForRole(Role::Web).size());
        // Проверяем, что у первой команды есть непустые title/description
        QVERIFY(!infos.at(0).title.isEmpty());
        QVERIFY(!infos.at(0).description.isEmpty());
    }
};

QTEST_MAIN(CommandRegistryTest)
#include "test_CommandRegistry.moc"

