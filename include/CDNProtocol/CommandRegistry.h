#pragma once
#include "Export.h"
#include "Roles.h"
#include "CommandEnums.h"
#include <QList>
#include <QString>

namespace CDNProtocol {

class CDNPROTOCOL_EXPORT CommandRegistry {
public:
    /// Информация о команде для UI/доки
    struct CommandInfo {
        Command cmd;
        QString name;
        QString title;
        QString description;
    };

    /// список доступных команд для роли
    static QList<Command> commandsForRole(Role role);

    /// проверка доступа
    static bool isAllowed(Role role, Command cmd);

    /// подробное описание для UI/документации
    static QList<CommandInfo> commandInfosForRole(Role role);
};

} // namespace CDNProtocol
