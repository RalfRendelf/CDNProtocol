#pragma once
#include "Export.h"
#include <QString>
#include <optional>
#include <QMap>

namespace CDNProtocol {


enum class Command {
    Register,
    StatusReport,
    RestartModule,
    Shutdown,
    GetLog,
    InsertEntry,
    UpdateEntry,
    DeleteEntry,
    FetchList,
    GetEntry,
    RenderPage,
    Ping
};


inline QString toString(Command c) {
    switch(c) {
    case Command::Register:      return "register";
    case Command::StatusReport:  return "statusReport";
    case Command::RestartModule: return "restartModule";
    case Command::Shutdown:      return "shutdown";
    case Command::GetLog:        return "getLog";
    case Command::InsertEntry:   return "insertEntry";
    case Command::UpdateEntry:   return "updateEntry";
    case Command::DeleteEntry:   return "deleteEntry";
    case Command::FetchList:     return "fetchList";
    case Command::GetEntry:      return "getEntry";
    case Command::RenderPage:    return "renderPage";
    case Command::Ping:          return "ping";
    }
    return {};
}

inline std::optional<Command> fromString(const QString &s) {
    static const QMap<QString,Command> map = {
        {"register",      Command::Register},
        {"statusReport",  Command::StatusReport},
        {"restartModule", Command::RestartModule},
        {"shutdown",      Command::Shutdown},
        {"getLog",        Command::GetLog},
        {"insertEntry",   Command::InsertEntry},
        {"updateEntry",   Command::UpdateEntry},
        {"deleteEntry",   Command::DeleteEntry},
        {"fetchList",     Command::FetchList},
        {"getEntry",      Command::GetEntry},
        {"renderPage",    Command::RenderPage},
        {"ping",          Command::Ping}
    };
    if (map.contains(s)) return map[s];
    return std::nullopt;
}
inline bool operator==(Command lhs, Command rhs) {
    return static_cast<std::underlying_type_t<Command>>(lhs) ==
           static_cast<std::underlying_type_t<Command>>(rhs);
}


} // namespace CDNProtocol
