#include "CDNProtocol/CommandRegistry.h"
#include <QMap>

using namespace CDNProtocol;

// таблица «роль → список команд»
static const QMap<Role, QList<Command>> roleMap = {
    { Role::Web, {
                    Command::StatusReport,
                    Command::FetchList,
                    Command::GetEntry,
                    Command::RenderPage
                }},
    { Role::AdminUI, {
                        Command::Register,
                        Command::StatusReport,
                        Command::RestartModule,
                        Command::Shutdown,
                        Command::GetLog,
                        Command::InsertEntry,
                        Command::UpdateEntry,
                        Command::DeleteEntry,
                        Command::FetchList,
                        Command::GetEntry
                    }},
    { Role::Db, {
                   Command::Register,
                   Command::InsertEntry,
                   Command::UpdateEntry,
                   Command::DeleteEntry,
                   Command::FetchList,
                   Command::GetEntry
               }},
    { Role::Generator, {
                          Command::Register,
                          Command::RenderPage
                      }},
    { Role::Central, {
                        Command::Register,
                        Command::Ping,
                        Command::StatusReport
                    }}
};

QList<Command> CommandRegistry::commandsForRole(Role role) {
    return roleMap.value(role);
}

bool CommandRegistry::isAllowed(Role role, Command cmd) {
    return roleMap.value(role).contains(cmd);
}

QList<CommandRegistry::CommandInfo> CommandRegistry::commandInfosForRole(Role role) {
    static const QMap<Command, CommandInfo> infoMap = {
        { Command::Register,      {Command::Register,      "register",      "Регистрация",         "Register client with server."} },
        { Command::StatusReport,  {Command::StatusReport,  "statusReport",  "Отчёт о статусе",     "Get system/module status."} },
        { Command::RestartModule, {Command::RestartModule, "restartModule", "Перезапуск модуля",   "Restart specified module."} },
        { Command::Shutdown,      {Command::Shutdown,      "shutdown",      "Остановка системы",   "Shutdown the system."} },
        { Command::GetLog,        {Command::GetLog,        "getLog",        "Получение логов",     "Fetch last N log entries."} },
        { Command::InsertEntry,   {Command::InsertEntry,   "insertEntry",   "Вставка записи",      "Insert new database entry."} },
        { Command::UpdateEntry,   {Command::UpdateEntry,   "updateEntry",   "Обновление записи",   "Update existing entry."} },
        { Command::DeleteEntry,   {Command::DeleteEntry,   "deleteEntry",   "Удаление записи",      "Delete entry by ID."} },
        { Command::FetchList,     {Command::FetchList,     "fetchList",     "Список записей",      "Fetch list of entries."} },
        { Command::GetEntry,      {Command::GetEntry,      "getEntry",      "Получение записи",     "Fetch entry by ID."} },
        { Command::RenderPage,    {Command::RenderPage,    "renderPage",    "Рендер страницы",      "Render a page template."} },
        { Command::Ping,          {Command::Ping,          "ping",          "Пинг",                "Heartbeat ping."} }
    };

    QList<CommandInfo> out;
    for (auto cmd : commandsForRole(role)) {
        if (infoMap.contains(cmd))
            out << infoMap.value(cmd);
    }
    return out;
}
